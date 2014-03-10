/*
思路：
剑指offer有，所以一次A掉。
从先序遍历数组找当前子树的跟节点，从中序遍历的数组中找左右子树的范围。
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
    //前提：节点的值不重复。
    int FindRootIndexFromInorder(vector<int> &inorder, int low, int high, int target)
    {
        for(int i = low; i <= high; i++)
        {
            if(inorder[i] == target)
                return i;
        }
        //return -1;
    }
    //前两参数是关联的，后三参数是关联的！
    TreeNode *CreateNode(vector<int>& preorder, int root_index, vector<int>& inorder, int low, int high)
    {
        TreeNode* p_node = new TreeNode(preorder[root_index]);
        int index = FindRootIndexFromInorder(inorder, low, high, preorder[root_index]);
        int left_len = index - low;
        int right_len = high - index;
        if(left_len > 0)
        {
            p_node->left = CreateNode(preorder, root_index+1, inorder, low, index-1);
        }
        if(right_len > 0)
        {
            p_node->right = CreateNode(preorder, root_index+1+left_len, inorder, index+1, high);
        }
        return p_node;
    }
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(preorder.empty())
            return NULL;
        TreeNode* p_root = CreateNode(preorder, 0, inorder, 0, inorder.size()-1);
        return p_root;
    }
};
