#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define m7 1000000007
#define ff first
#define ss second
#define pb push_back
#define rep(n) for(int i=0; i<n; i++)

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

bool pof2(int n){	//Check whether a number is a power of 2.
    if(n < 1)
        return false;
    double logn = log2(n);
    return floor(logn) == ceil(logn);
}

template<typename T>
class btNode{

public:
    T data;
    btNode* left;
    btNode* right;

    btNode(T data){
        this->data = data;
        left = right = 0;
    }

    ~btNode(){
        delete left, right;
    }
};

void printBTree(btNode<int>* root){

    if(root == 0)
        return;
    cout << root->data << ": ";
    if(root->left) cout << root->left->data << ' ';
    if(root->right) cout << root->right->data;
    cout << endl;
    printBTree(root->left);
    printBTree(root->right);
}

void printBTreeLevelWise(btNode<int>* root){    // level order traversal

    if(root == 0)
        return;
    
    queue<btNode<int>*> q;
    q.push(root);

    while(!q.empty()){

        btNode<int>* node = q.front();
        q.pop();

        cout << node->data << ' ';
        if(node->left)
            q.push(node->left);
        if(node->right)
            q.push(node->right);
    }
}

btNode<int>* takeInput(){

    int data;
    cin >> data;
    btNode<int>* root = new btNode<int>(data);

    int l, r;
    cin >> l >> r;
    if(l)
        root->left = takeInput();
    if(r)
        root->right = takeInput();
    return root;
}

btNode<int>* takeInputLevelWise(){

    int data; 
    cin >> data;
    btNode<int>* root = new btNode<int>(data);

    queue<btNode<int>*> q;
    q.push(root);
    while(!q.empty()){

        btNode<int>* node = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;
    
        if(l){
            cin >> data;
            node->left = new btNode<int>(data);
            q.push(node->left);
        }
        if(r){
            cin >> data;
            node->right = new btNode<int>(data);
            q.push(node->right);
        }
    }
    return root;
}

int countNodes(btNode<int>* root){

    if(root == 0)
        return 0;
    
    int cnt = 1;
    cnt += countNodes(root->left);
    cnt += countNodes(root->right);
    return cnt;
}

bool searchX(btNode<int>* root, int x){

    if(root == 0)
        return false;
    if(root->data == x)
        return true;
    return searchX(root->left, x) || searchX(root->right, x);
}

int height(btNode<int>* root){

    if(root == 0)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

void mirror(btNode<int>* root){

    if(root == 0)
        return;
    swap(root->left, root->right); // You cannot swap data since, nodes can be null 
    // X swap(root->left->data, root->right->data)
    mirror(root->left);
    mirror(root->right);
}

void PreOrder(btNode<int>* root){

    if(root == 0)
        return;

    cout << root->data << ' ';
    PreOrder(root->left);
    PreOrder(root->right);
}

void PostOrder(btNode<int>* root){

    if(root == 0)
        return;
    
    PostOrder(root->left); PostOrder(root->right);
    cout << root->data << ' ';
}

void Inorder(btNode<int>* root){

    if(root == 0)   
        return;

    Inorder(root->left);
    cout << root->data << ' ';
    Inorder(root->right);
}

btNode<int>* CFPI(int inorder[], int preorder[], int ins, int ine, int pres, int pree){

    if(ins > ine)
        return 0;

    int data = preorder[pres];
    btNode<int>* root = new btNode<int>(data);

    int p = find(inorder + ins, inorder + ine + 1, data) - inorder;

    int lins = ins;
    int line = p - 1;
    int lpres = pres + 1;
    int lpree = line - lins + lpres;

    int rpres = lpree + 1;
    int rpree = pree;
    int rins = p + 1;
    int rine = ine;

    root->left = CFPI(inorder, preorder, lins, line, lpres, lpree);
    root->right = CFPI(inorder, preorder, rins, rine, rpres, rpree);
    return root;
}

// 1 1 1 4 2 0 0 1 1 3 5 0 0 0 0 - demo binary tree
int main() {

    fastIO();

    //btNode<int>* r = takeInputLevelWise();
    //printBTree(r);
    //printBTreeLevelWise(r);

    cout << endl;
    //cout << searchX(r, 7) << endl;
    //cout << countNodes(r) << endl;
    //mirror(r);
    
    // PreOrder(r); cout << endl;
    // PostOrder(r); cout << endl;
    // Inorder(r);

    int inorder[] = {1, 2, 4, 5, 3, 6, 7};
    int preorder[] = {4, 2, 5, 1, 6, 3, 7};

    printBTreeLevelWise(CFPI(preorder, inorder, 0, 6, 0, 6));
}