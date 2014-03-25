/*
思路：后序遍历树。判断左子树和右子树的高度差。一次A掉！
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
    bool Postorder(TreeNode *p_node, int &node_height)
    {
        if(p_node == NULL)
        {
            node_height = -1;
            return true;
        }
        int left_height = 0;
        int right_height = 0;
        bool left = Postorder(p_node->left, left_height);
        if(!left) { return false;}
        bool right = Postorder(p_node->right, right_height);
        if(!right) {return false;}
        int diff = left_height - right_height;
        if(diff >= -1 && diff <= 1)
        {
            node_height = (left_height > right_height ? left_height: right_height) + 1;
            return true; 
        }
        return false;
    }
    bool isBalanced(TreeNode *root) {
        int node_height = 0;
        return Postorder(root, node_height);
    }
};
