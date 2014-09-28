/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        stack<TreeNode *> nodes;
        vector<int> result;
        while(root != NULL || !nodes.empty())
        {
            while(root)
            {
                nodes.push(root);
                root = root->left;
            }
            if(!nodes.empty())
            {
                root = nodes.top();
                nodes.pop();
                result.push_back(root->val);
                root = root->right;
            }
        }
        return result;
    }
};
