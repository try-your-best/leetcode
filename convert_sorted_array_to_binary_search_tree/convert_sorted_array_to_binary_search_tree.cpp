/*
思路：每次取数组的中间节点！
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
    TreeNode* transform(vector<int> &num, int start, int end) 
    {
        if(start <= end)
        {
            int middle = (start+end)/2;
            TreeNode* pNode = new TreeNode(num[middle]);
            pNode->left = transform(num, start, middle-1);
            pNode->right = transform(num, middle+1, end);
            return pNode;
        }
        return NULL;
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if(num.empty())
            return NULL;
        return transform(num, 0, num.size()-1);
    }
};
