/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//optimized approach: add a check while calc. height
//if at any point, diff.>1, break


class Solution {
public:

    int heightcheck(TreeNode* root)
    {
        if(!root) return 0;

        int left = heightcheck(root->left);

        if(left == -1) return -1;
        int right = heightcheck(root->right);
        if(right == -1) return -1;

        
        if(abs(right - left) > 1) return -1;

        return 1 + max(right, left);
    }
    bool isBalanced(TreeNode* root) {

        return !(heightcheck(root) == -1);
        
    }
};
