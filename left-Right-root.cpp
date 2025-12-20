#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree(vector<int>& preorder, int& idx) {
    idx++;

    if ( preorder[idx] == -1) {
        return NULL;    
    }

    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder, idx);
    root->right = buildTree(preorder, idx);

    return root;
}

void postorderPrint(Node* root) {
    if (root == NULL) 
    {
     return;
    }
    postorderPrint(root->left);
    postorderPrint(root->right);
    cout << root->data << " ";
}

int main() {
    vector<int> postorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    int idx = -1;
    Node* root = buildTree(postorder, idx);

    postorderPrint(root);
    cout << endl;

    return 0;
}
