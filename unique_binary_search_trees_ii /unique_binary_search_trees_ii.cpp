/*
思路：找到一个数作为根结点，剩余的数分别划入左子树或者右子树。这个规律要从
Unique Binary Search Trees 学习！
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
    vector<TreeNode *> createTree(int start, int end)
    {
        vector<TreeNode *> result;
        if(start > end)
        {
            result.push_back(NULL);
            return result;
        }
        for(int k = start; k <= end; ++k)
        {
            vector<TreeNode *> left = createTree(start, k-1);
            vector<TreeNode *> right = createTree(k+1, end);
            for(int i = 0; i < left.size(); ++i)
            {
                for(int j = 0; j < right.size(); ++j)
                {
                      TreeNode* root = new TreeNode(k);//note:每次修改左右子树，当前节点就要重新创建！
                      root->left = left[i];
                      root->right = right[j];
                      result.push_back(root);
                }
            }
        }
        return result;
    }
    vector<TreeNode *> generateTrees(int n) {
        return createTree(1, n);
    }
};
