/*
思路：果断先序遍历!
determine if the tree has a root-to-leaf path
注意，是要求根节点到叶子节点的路径和，只有左右节点皆为NULL才为叶子节点！
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
    bool Preorder(TreeNode *p_node, int cur_value)
    {
        if(p_node == NULL)
        {
            return false;
        }
        else if(p_node->left == NULL && p_node->right == NULL)//左右节点皆为NULL为叶子节点！
        {
            if(cur_value - p_node->val == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        bool left = Preorder(p_node->left, cur_value - p_node->val);
        if(left)
        {
            return true;
        }
        bool right = Preorder(p_node->right, cur_value - p_node->val);
        return right; 
    }
    bool hasPathSum(TreeNode *root, int sum) {
        return Preorder(root, sum);
    }
};
