/*
思路：BST的中序遍历是升序的数组！如果数组存在逆序则不是BST。
注意，不能仅仅通过root，left,right 的关系来判断是否为BST。
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
    vector<int> values;
    void inorder(TreeNode *root)
    {
        if(!root)
            return;
        inorder(root->left);
        values.push_back(root->val);
        inorder(root->right);
    }
    bool isValidBST(TreeNode *root) {
        if(!root)
            return true;
        values.clear();
        inorder(root);
        int size = values.size();
        for(int i = 0; i < size-1; ++i)
        {
            if(values[i] >= values[i+1])
            {
                return false;
            }
        }
        return true;
    }
};
