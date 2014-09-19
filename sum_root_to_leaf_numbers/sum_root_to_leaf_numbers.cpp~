/*
先序遍历，找到路径，求和。
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
    int sum;
    vector<int> digits;
    
    void preOrder(TreeNode *pNode)
    {
        if(pNode == NULL)
        {
            return;
        }
        digits.push_back(pNode->val);
        if(!pNode->left && !pNode->right)
        {
            int result = 0;
            for(int i = 0; i < digits.size(); ++i)
            {
                result = result*10 + digits[i];
            }
            sum += result;
        }
        if(pNode->left)
            preOrder(pNode->left);
        if(pNode->right)
            preOrder(pNode->right);
        digits.pop_back();
    }
    
    int sumNumbers(TreeNode *root) {
        if(!digits.empty())
            digits.clear();
        sum = 0;
        preOrder(root);
        return sum;
    }
};
