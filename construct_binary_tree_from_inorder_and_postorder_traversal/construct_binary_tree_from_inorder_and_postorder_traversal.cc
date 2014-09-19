#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int FindRootIndex(vector<int> &inorder, int low, int high, int target)
    {
        for(int i = low; i <= high; i++)
        {
            if(inorder[i] == target)
            {
                return i;
            }
        }
        cout << "error:" << target <<"--"<<low << "--"<< high << endl;
        return -1;
    }
    TreeNode *CreateNode(vector<int> &postorder, int root_index, vector<int> &inorder, int low, int high)
    {
        TreeNode * p_node = new TreeNode(postorder[root_index]);
        int index = FindRootIndex(inorder, low, high, postorder[root_index]);
        int left_len = index - low;
        int right_len = high - index;
        if(left_len > 0)
        {
            //p_node->left = CreateNode(postorder, low+left_len-1, inorder, low, index-1);
        	  //注意，定位下一个根节点时不要用low+left_len-1，因为low是针对inorder的参数！！！
            p_node->left = CreateNode(postorder, root_index-right_len-1, inorder, low, index-1);
        }
        if(right_len > 0)
        {
            p_node->right = CreateNode(postorder, root_index-1, inorder, index+1, high);
        }
        return p_node;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(inorder.empty() || inorder.size() != postorder.size())
        {
            return NULL;
        }
        TreeNode *p_root = CreateNode(postorder, postorder.size()-1,inorder, 0, inorder.size()-1);
        return p_root;
    }
};

void Inorder(TreeNode *p_node)
{
    if(p_node == NULL)
    {
        return;
    }
    Inorder(p_node->left);
    cout << p_node->val << " ";
    Inorder(p_node->right);
}

void Test()
{
    int a[] = {-4,-10,3,-1,7,11,-8,2};
    //int a[] = {1,2,3};
    vector<int> inorder(a, a + sizeof(a)/sizeof(int));
    int b[] = {-4,-1,3,-10,11,-8,2,7};
    //int b[] = {1,3,2};
    vector<int> postorder(b, b + sizeof(b)/sizeof(int));
    Solution s;
    TreeNode *p_root = s.buildTree(inorder, postorder);
    Inorder(p_root);
    cout << endl;
}

int main()
{
    Test();
    return 0;
}
