//通过中序遍历树的方法无法判断二叉树是否对称。
//例如：{1,2,3,3,#,2,#} （二叉树的序列化表示！）

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
    void InorderWalk(TreeNode* p_node, vector<TreeNode*>& nodes)
    {
        if(p_node == NULL)
            return;
            
        if(p_node->left != NULL)
            InorderWalk(p_node->left, nodes);
            
        nodes.push_back(p_node);
        
        if(p_node->right != NULL)
            InorderWalk(p_node->right, nodes);
    }
public:
    bool isSymmetric(TreeNode *root) {
        if(root == NULL)
            return true;
        vector<TreeNode*> nodes;
        InorderWalk(root, nodes);
        int len = nodes.size();
        if(len & 1 == 1)
        {
            int mid = (len - 1)/2;
            if(nodes[mid] != root)
                return false;
                
            for(int i = 0; i < mid; i++)
            {
                if(nodes[i]->val != nodes[len-1-i]->val)
                    return false;
            }
            return true;
        }
        else
        {
            return false;
        }
    }
};
