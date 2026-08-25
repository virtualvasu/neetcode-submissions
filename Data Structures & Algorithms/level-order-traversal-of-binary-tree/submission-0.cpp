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

//use BFS
//create a queue 
//while q is not empty
//will create new vector for each level -> add elem only for that level
//push to queue




class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        if (!root) return ans;

        queue <TreeNode*> q;

        q.push(root);

        while(!q.empty())
        {
            int n = q.size();
            vector<int> level;

            TreeNode* node = q.front();

            for(int i =0;i<n; i++)
            {
                
                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }


            ans.push_back(level);
        }

        return ans;
        
    }
};
