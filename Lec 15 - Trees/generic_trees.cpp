// 2 Types of Data Structures
// A. which changes how data is stored in memory. Ex - Arrays, Linked Lists
// B. layer above a basic data structure which defines how data is accessible to user. Ex - Stack, Queue

/* Trees - 
    Applications - File & Directory Organization in a Computers, Organization Structure of Company
    Recursive Data Structure - 95% using recursion to solve any tree related problem
*/

// Height of a Tree
// It can be defined in 2 ways (both correct), 
//   1. root node - height 0
//   2. root node - height 1

#include <bits/stdc++.h>
#include "TreeNode.h"

using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define m7 1000000007
#define ff first
#define ss second
#define pb push_back
#define rep(n) for(int i=0; i<n; i++)

void printTree(TreeNode<int>* root){     // PreOrder Traversal

    if(root == 0)
        return;
    cout << root->data << ": ";
    for(int i=0; i<root->children.size(); i++)
        cout << root->children[i]->data << " ";
    cout << endl;
    for(int i=0; i<root->children.size(); i++)
        printTree(root->children[i]);
}

void printTreeLevelWise(TreeNode<int>* root){

    if(root == 0)
        return;
    queue<TreeNode<int>*> q;
    q.push(root);

    while(!q.empty()){

        TreeNode<int>* node = q.front();
        q.pop();
        cout << node->data << ' ';
        rep(node->children.size())
            q.push(node->children[i]);
    }
}

TreeNode<int>* takeInput(){

    int data; 
    cout << "Enter Data: ";
    cin >> data;

    TreeNode<int>* root = new TreeNode<int>(data);
    int children;
    cout << "Enter no. of children: ";
    cin >> children;
    rep(children)
        root->children.pb(takeInput());
    return root;
}

TreeNode<int>* takeInputLevelWise(){

    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> q;
    q.push(root);

    while(!q.empty()){
        
        TreeNode<int>* node = q.front();
        q.pop();
        
        int children;
        cin >> children;

        rep(children){
            int data;
            cin >> data;
            TreeNode<int>* child = new TreeNode<int>(data);
            node->children.pb(child);
            q.push(child);
        }
    }
    return root;
}

int countNodes(TreeNode<int>* root){

    if(root == 0)
        return 0;

    int cnt = 1;
    rep(root->children.size())
        cnt += countNodes(root->children[i]);
    return cnt;
}

int sumNodes(TreeNode<int>* root){

    if(root == 0)
        return 0;
    int sum = root->data;
    rep(root->children.size())
        sum += sumNodes(root->children[i]);
    return sum;
}

TreeNode<int>* maxDataNode(TreeNode<int>* root){

    if(root == 0)
        return 0;
    TreeNode<int>* maxNode = root;
    rep(root->children.size()){
        TreeNode<int>* maxNodeFromChildren = maxDataNode(root->children[i]);
        if(maxNodeFromChildren->data > maxNode->data)
            maxNode = maxNodeFromChildren;
    }
    return maxNode;
}

int heightTree(TreeNode<int>* root){

    if(root == 0)
        return 0;
    
    int maxHeight = 0;
    rep(root->children.size())
        maxHeight = max(maxHeight, heightTree(root->children[i]));
    return 1 + maxHeight;
}

void printDepthD(TreeNode<int>* root, int d){

    if(root == 0)
        return;
    if(d == 0){
        cout << root->data << ' ';
        return;
    }
    rep(root->children.size())
        printDepthD(root->children[i], d-1);
}

int leafNodes(TreeNode<int>* root){

    if(root == 0)
        return 0;
    if(root->children.size() == 0)
        return 1;
    int cnt = 0;
    rep(root->children.size())
        cnt += leafNodes(root->children[i]);
    return cnt;
}

void PostOrder(TreeNode<int>* root){

    if(root == 0)
        return;
    rep(root->children.size())
        PostOrder(root->children[i]);
    cout << root->data << ' ';
}

void DeleteTree(TreeNode<int>* root){

    rep(root->children.size())
        DeleteTree(root->children[i]);
    delete root;
}

// Demo Tree - 1 2 2 3 2 5 7 0 0 0

int main(){

    // TreeNode<int> root(6);
    // root.children.push_back(new TreeNode<int>(5));
    // root.children.push_back(new TreeNode<int>(7));
    // The above is valid but we don't do it this way, why??

    TreeNode<int>* root = new TreeNode<int>(1);
    TreeNode<int>* n1 = new TreeNode<int>(2);
    TreeNode<int>* n2 = new TreeNode<int>(3);

    n1->children.pb(new TreeNode<int>(7)); n1->children.pb(new TreeNode<int>(11));

    root->children.pb(n1); root->children.pb(n2);
    printTree(root);
    cout << endl;

    // TreeNode<int>* r1 = takeInput();
    // printTree(r1);
    // cout << endl;

    // TreeNode<int>* r2 = takeInputLevelWise();
    // printTree(r2);
    // cout << endl;
    // printTreeLevelWise(r2);
    // cout << endl;
    // cout << "No. of Nodes: " << countNodes(r2) << endl;
    // cout << "Sum of all Nodes: " << sumNodes(r2) << endl;
    // cout << "Data of Max Node: " << maxDataNode(r2)->data << endl;
    // cout << "Height of the Tree: " << heightTree(r2) << endl;
    // cout << "All Nodes at Depth d: "; printDepthD(r2, 2);
    // cout << endl;
    // int cnt = 0;
    // cout << "No. of Leaf Nodes: " << leafNodes(r2) << endl;

    TreeNode<int>* r3 = takeInputLevelWise();
    PostOrder(r3);

    // Destroy the tree
    delete r3;
}

