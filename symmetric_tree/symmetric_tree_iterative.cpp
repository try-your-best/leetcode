/*
���������ѭ���������Ƚϣ��ᷢ������ʽ���кܶ����Ƶ㡣
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
private:
    bool CheckSymmetricPreorderInterative(TreeNode* p_node1, TreeNode* p_node2)
    {
        stack<TreeNode*> left_subtree;
        stack<TreeNode*> right_subtree;
        while(p_node1 != NULL || !left_subtree.empty() || p_node2 != NULL || !right_subtree.empty())
        {
            while(p_node1 != NULL || p_node2 != NULL)
            {
                if(p_node1 != NULL && p_node2 != NULL && p_node1->val == p_node2->val)
                {
                    left_subtree.push(p_node1);
                    right_subtree.push(p_node2);
                    p_node1 = p_node1->left;
                    p_node2 = p_node2->right;//���������ȷ����ҽڵ㣬�����������෴
                }
                else
                {
                    return false;
                }
            }
            if(!left_subtree.empty() || !right_subtree.empty())
            {
                if( !left_subtree.empty() && !right_subtree.empty()) //��ʽ���������while��Ӧ
                {
                    p_node1 = left_subtree.top();
                    left_subtree.pop();
                    p_node1 = p_node1->right;
                    
                    p_node2 = right_subtree.top();
                    right_subtree.pop();
                    p_node2 = p_node2->left;//�������Ƿ�����ڵ㣬�����������෴
                }
                else 
                {
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isSymmetric(TreeNode *root) {
        if(root == NULL)
            return true;
        return CheckSymmetricPreorderInterative(root->left, root->right);
    }
};

