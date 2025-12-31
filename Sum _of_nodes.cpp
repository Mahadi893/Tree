#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
static int idx = -1;
Node* buildTree(vector<int>preorder)
{
    idx++;
    if(preorder[idx] == -1)
    {
        return NULL;
    }
    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}
void postorderPrint(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    postorderPrint(root->left);
    postorderPrint(root->right);    
    cout<<root->data<<" ";
}
int height(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight,rightHeight) + 1;
}
int countNodes(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int leftCount = countNodes(root->left);
    int rightCount = countNodes(root->right);
    return leftCount + rightCount + 1;
}
int sum(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int leftSum = sum(root->left);
    int rightSum = sum(root->right);
    return leftSum + rightSum + root->data;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int>preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(preorder);
    postorderPrint(root);
    cout<<endl;
    cout<<"Height of tree : "<<height(root)<<endl;
    cout<<"Number of nodes : "<<countNodes(root)<<endl;
    cout<<"Sum of nodes : "<<sum(root)<<endl;

    return 0;
}
