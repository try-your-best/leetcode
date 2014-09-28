/*
思路：先中序遍历，得到升序列表。然后判断交换位置的点的位置。
如果交换点相邻，则只有一个降序。
如果交换点不相邻，则有一个降序，和一个升序。交换降序的头节点和升序的尾节点。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


 // Definition for binary tree
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 class Solution {
 public:
     vector<TreeNode*> nodes;
     void inorder(TreeNode* root)
     {
         if(!root)
         {
             return;
         }
         inorder(root->left);
         nodes.push_back(root);
         inorder(root->right);
     }

     void recoverTree(TreeNode *root) {
         nodes.clear();
         inorder(root);
         int index1 = -1;  int index2 = -1;
         int size = nodes.size();
         int state = 0;
         for(int i = 0; i < size-1; ++i)
         {
             if(state == 0)
             {
                 if(nodes[i]->val > nodes[i+1]->val)//note: not nodes[i] > nodes[i+1]
                 {
                     index1 = i;
                     state = 1;
                 }
             }
             else if(state == 1)
             {
                 if(nodes[i]->val > nodes[i+1]->val)
                 {
                     index2 = i+1;
                     state = 2;
                     break;
                 }
             }
         }
         if(state == 1)
         {
             swap(nodes[index1]->val, nodes[index1+1]->val);
         }
         else if(state == 2)
         {
             swap(nodes[index1]->val, nodes[index2]->val);
         }
     }
 };

void test()
{
	TreeNode n1(0);
	TreeNode n2(1);
	n1.left = &n2;
	cout << n1.val <<"," << n2.val << endl;
	Solution s;
	s.recoverTree(&n1);
	cout << n1.val <<"," << n2.val << endl;
}

int main()
{
	test();
	return 0;
}

