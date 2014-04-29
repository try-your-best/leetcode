/*
思路：先序遍历！
*/
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
    void PreOrder(TreeNode *p_node, vector<int> &nodes)
    {
        if(p_node == NULL)
        {
            return;
        }
        nodes.push_back(p_node->val);
        PreOrder(p_node->left, nodes);
        PreOrder(p_node->right, nodes);
    }
    vector<int> preorderTraversal(TreeNode *root) {
         vector<int> nodes;
         PreOrder(root, nodes);
         return nodes;
    }
};
