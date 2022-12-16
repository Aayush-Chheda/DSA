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

bool containsX(TreeNode<int>* root, int x){

    if(root == 0)
        return false;
    if(root->data == x)
        return true;
    rep(root->children.size())
        if(containsX(root->children[i], x))
            return true;
    return false;
}

int helperNodeSum(TreeNode<int>* root){

    if(root == 0)
        return 0;
    int sum = root->data;
    rep(root->children.size())
        sum += root->children[i]->data;
    return sum;
}

TreeNode<int>* nodeWithMaxChildSum(TreeNode<int>* root){

    if(root == 0)
        return 0;
    
    int sum = helperNodeSum(root);
    TreeNode<int>* maxNode = root;

    rep(root->children.size()){
        int sumChild = helperNodeSum(root->children[i]);
        if(sumChild > sum)
            maxNode = root->children[i];
    }
    return maxNode;
}

TreeNode<int>* nextLarger(TreeNode<int>* root, int n){

    if(root == 0)
        return 0;

    TreeNode<int>* nextLargerNode = 0;
    if(root->data > n)
        nextLargerNode = root;

    rep(root->children.size()){
        TreeNode<int>* nextLargerNodeChild = nextLarger(root->children[i], n);
        if(!nextLargerNode)
            nextLargerNode = nextLargerNodeChild;
        else if(nextLargerNodeChild->data < nextLargerNode->data)
            nextLargerNode = nextLargerNodeChild;
    }
    return nextLargerNode;
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

TreeNode<int>* secondLargest(TreeNode<int>* root, TreeNode<int>* &first, TreeNode<int>* &second){

    if(root == 0)
        return 0;
    
    if(!first)  
        first = root;
    else if(root->data > first->data){
        second = first;
        first = root;
    } 
    else if(!second && root->data < first->data)
        second = root;
    else if(root->data > second->data && root->data < first->data)
        second = root;

    rep(root->children.size())
        secondLargest(root->children[i], first, second);
    
    return second;
}

void replaceDepth(TreeNode<int>* root, int d){

    if(root == 0)
        return;
    
    root->data = d;
    rep(root->children.size())
        replaceDepth(root->children[i], d+1);
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
    cout << endl;
}

void printTreeLevelWiseInLine(TreeNode<int>* root){

    if(root == 0)
        return;
    queue<pair<TreeNode<int>*,int>> q;
    q.push(make_pair(root, 0));
    int printedDepth = 0;
    while(!q.empty()){
        TreeNode<int>* node = q.front().first;
        int depth = q.front().second;
        q.pop();
        if(depth > printedDepth){
            cout << endl;
            printedDepth = depth;
        }
        cout << node->data << ' ';
        rep(node->children.size())
            q.push(make_pair(node->children[i], depth+1));
    }
    cout << endl;
}

// 1 3 3 5 7 2 11 10 1 9 1 8 0 0 0 0
int main() {

    int x = 9;
    //int n = 21;
    // TreeNode<int> *first, *second;
    // first = second = 0;
    TreeNode<int>* root = takeInputLevelWise();
    // printTreeLevelWiseInLine(root);      // check this out
    cout << containsX(root, x) << endl;

    // cout << nodeWithMaxChildSum(root)->data << endl;
    //cout << nextLarger(root, n)->data << endl;
    //cout << secondLargest(root, first, second)->data << endl;
    //replaceDepth(root, 0);
    //printTreeLevelWise(root);   
}