/*
思路：先序遍历二叉树，每次到叶子节点就计算当前路径的长度，与目标长度进行比较。
剑指offer有。本来应该是一次A掉，结果还是因为不小心出现一次编译错误。
*/

#include <iostream>
#include <vector>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


 //Definition for binary tree
 struct TreeNode 
 {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
 
class Solution {
public:
    void PreOrder(TreeNode* p_node, int target_sum, vector<int>& values, vector<vector<int> >& path)
    {
        if(p_node == NULL)
            return;
        values.push_back(p_node->val);
        bool is_leaf = p_node->left == NULL && p_node->right == NULL;
        if(is_leaf)
        {   
            int sum = 0;
            for(vector<int>::iterator iter = values.begin(); iter != values.end(); iter++)
            {
                sum += *iter;
            }
            if(sum == target_sum)
            {
                path.push_back(values);
            }
            return;
        }
        if(p_node->left != NULL)
        {
            PreOrder(p_node->left, target_sum, values, path);
            values.pop_back(); // 注意！这里是values.pop_back()，不是path.pop_back()
        }
        if(p_node->right != NULL)
        {
            PreOrder(p_node->right, target_sum, values, path);
            values.pop_back();
        }
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > path;
        vector<int> values;
        PreOrder(root, sum, values, path);
        return path;
    }
};

void Test()
{
	TreeNode n1(1);
	TreeNode n2(2);
	n1.left = &n2;
	Solution s;
	vector<vector<int> > path = s.pathSum(&n1,0);
	cout << "ok" << endl;
}

int main(int argc, char *argv[]) {
	Test();
	return 0;
}
