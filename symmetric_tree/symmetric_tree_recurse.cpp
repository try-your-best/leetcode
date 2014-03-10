//思路：同时遍历左子树和右子树的对应节点！！
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
    bool CheckSymmetric(TreeNode* p_node1, TreeNode* p_node2)
    {
        if(p_node1 == NULL)
        {
            if(p_node2 == NULL)
                return true;
            else
                return false;
        }
        if(p_node2 == NULL)
        {
            if(p_node1 == NULL)
                return true;
            else
                return false;
        }
        if(p_node1->val != p_node2->val) //剪枝！
            return false;
        bool left =  CheckSymmetric(p_node1->left, p_node2->right);  //注意，由于是对称，所以是检查p_node1的左节点和P_node2的右节点！
        bool right = CheckSymmetric(p_node1->right, p_node2->left);
        return left && right;
    }
public:
    bool isSymmetric(TreeNode *root) {
        if(root == NULL)
            return true;
        return CheckSymmetric(root->left, root->right);
    }
};
