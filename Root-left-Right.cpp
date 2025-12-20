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

void preorderPrint(Node* root) {
    if (root == NULL) return;

    cout << root->data << " ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

int main() {
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    int idx = -1;
    Node* root = buildTree(preorder, idx);

    preorderPrint(root);
    cout << endl;

    return 0;
}

//Output:
//1,2,3,4,5

