/*
You may only use constant extra space.
You may assume that it is a perfect binary tree 
(ie, all leaves are at the same level, and every parent has two children).
在网上找到更优做法！
思路：
广度优先，利用map区分层次。
 */

#include <iostream>
#include <queue>
#include <map>
using namespace std;

// Definition for binary tree with next pointer.
struct TreeLinkNode
{
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) :
			val(x), left(NULL), right(NULL), next(NULL)
	{
	}
};

class Solution
{
public:
	void connect(TreeLinkNode *root)
	{
		if (root == NULL)
			return;
		queue<TreeLinkNode*> nodes;
		map<TreeLinkNode*, int> nodeLevel;
		nodes.push(root);
		nodeLevel[root] = 0;
		while (!nodes.empty())
		{
			TreeLinkNode* pCur = nodes.front();
			nodes.pop();
			if (nodes.empty() || nodeLevel[pCur] < nodeLevel[nodes.front()])
			{
				pCur->next = NULL;
			}
			else
			{
				pCur->next = nodes.front();
			}
			if (pCur->left)
			{
				nodes.push(pCur->left);
				nodeLevel[pCur->left] = nodeLevel[pCur] + 1;
			}
			if (pCur->right)
			{
				nodes.push(pCur->right);
				nodeLevel[pCur->right] = nodeLevel[pCur] + 1;
			}
		}
	}
};

void test()
{
	TreeLinkNode n1(1);
	TreeLinkNode n2(2);
	TreeLinkNode n3(3);
	n1.left = &n2;
	n1.right = &n3;
	Solution s;
	s.connect(&n1);
}

int main()
{
	test();
	return 0;
}
