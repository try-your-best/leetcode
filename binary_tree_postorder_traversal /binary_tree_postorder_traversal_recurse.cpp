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
private:
    void PostorderWalk(TreeNode *p_node, vector<int>& nodes)
    {
        if(p_node == NULL)
            return;
        if(p_node->left != NULL)
        {
            PostorderWalk(p_node->left, nodes);
        }
        if(p_node->right != NULL)
        {
            PostorderWalk(p_node->right, nodes);
        }
        nodes.push_back(p_node->val);
    }
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> nodes;
        PostorderWalk(root, nodes);
        return nodes;
    }
};
