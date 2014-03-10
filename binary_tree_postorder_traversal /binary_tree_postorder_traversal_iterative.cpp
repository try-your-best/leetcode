/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    void PostorderWalk(TreeNode *p_node, vector<int>& nodes)
    {
        stack<TreeNode*> node_stack;
        TreeNode *pre_visited = NULL;
        while(p_node != NULL || !node_stack.empty())
        {
            while(p_node != NULL)
            {
                node_stack.push(p_node);
                p_node = p_node->left;
            }
            if(!node_stack.empty())
            {
                p_node = node_stack.top();
		 //��ʱ��ջ�У���ǰ�ڵ�һ������ڵ���·����������ж�NULLʱֻ���ע�ҽڵ�ġ�
                if(p_node->right == NULL || p_node->right == pre_visited)
                {
                    nodes.push_back(p_node->val);
                    node_stack.pop();
                    pre_visited = p_node;
                    p_node = NULL; //����ΪNULL����Ϊ�������ʵģ�֮��͸õ�ջ�ˡ�
                }
                else
                {
                    p_node = p_node->right;
                }
            }
            
        }
    }
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> nodes;
        PostorderWalk(root, nodes);
        return nodes;
    }
};

void PrintNodes(const vector<int>& nodes)
{
    for(int i = 0; i < nodes.size(); i++)
        cout << nodes[i] << " ";
    cout << endl;
}

void Test()
{
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    n1.right = &n2;
    n2.left = &n3;
    Solution s;
    PrintNodes(s.postorderTraversal(&n1));
}

int main()
{
    Test();
    return 0;
}
