/*
这个不是题解，题目是要求用节点的右指针实现单链表。这是用左指针实现的！
*/

#include<iostream>

using namespace std;
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    void flatten(TreeNode *root) {
        if(root == NULL)
            return;
        flatten(root->left);
        flatten(root->right);
        if(root->right == NULL)
            return;
        TreeNode* p_node = root->left;
        if(p_node == NULL)
        {
            root->left = root->right;
        }
        else
        {
            while(p_node->left != NULL)
            {
                p_node = p_node->left;
            }
            p_node->left = root->right;
        }
        root->right = NULL;
    }
};

void Print(TreeNode * p_node)
{
    while(p_node != NULL)
    {
        cout << p_node->val << " ";
        p_node = p_node->left;
    }
    cout << endl;
}

void Test()
{
    TreeNode n1(1);
    TreeNode n2(2);
    n1.right = &n2;
    Solution s;
    s.flatten(&n1);
    Print(&n1);
}

int main()
{
    Test();
    return 0;
}
