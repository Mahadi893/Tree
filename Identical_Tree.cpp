#include <bits/stdc++.h>
using namespace std;

// Definition of Tree Node
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

// Solution class
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base case
        if (p == NULL || q == NULL) {
            return p == q;
        }

        // Recursive calls
        bool isLeftSame = isSameTree(p->left, q->left);
        bool isRightSame = isSameTree(p->right, q->right);

        // Compare values + structure
        return isLeftSame && isRightSame && p->val == q->val;
    }
};

int main() {
    // -------- Tree 1 --------
    //     1
    //    / \
    //   2   3
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    // -------- Tree 2 --------
    //     1
    //    / \
    //   2   3
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    // Create Solution object
    Solution obj;

    // Check if trees are same
    if (obj.isSameTree(p, q)) {
        cout << "Trees are SAME" << endl;
    } else {
        cout << "Trees are DIFFERENT" << endl;
    }

    return 0;
}
