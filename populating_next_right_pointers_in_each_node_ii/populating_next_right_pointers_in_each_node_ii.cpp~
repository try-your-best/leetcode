/*
这题与上道题不同点在于二叉树不是完全二叉树，因此结构差别较大，不能用上道题的方法。
如果当前节点有左右子节点，先把他们链接起来，因为肯定是相邻的。
然后通过root的next指针，找到需要与当前节点子节点连接的后继节点。
因为涉及到root的next指针查询，递归需要先处理完右子树，以便左子树节点next指针的连接。
参考：http://blog.csdn.net/havenoidea/article/details/12849047

在递归处理二叉树时，常常以root left right 三个节点为中心去考虑问题！
*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root)
            return;
        TreeLinkNode* needNext = root->left;
        TreeLinkNode* tmp = root->next;
        if(root->left && root->right)
        {
            needNext = root->right;
            root->left->next = root->right;
        }
        else if(root->right)
            needNext = root->right;
        else if(root->left)
            needNext = root->left;
        else
            needNext = NULL;
            
        if(needNext)
        {
            while(tmp)
            {
                if(tmp->left)
                {
                    needNext->next = tmp->left;
                    break;
                }
                else if(tmp->right)
                {
                    needNext->next = tmp->right;
                    break;
                }
                else
                {
                   tmp = tmp->next; 
                }
            }
        }
        connect(root->right);//note 要先递归右子树！
        connect(root->left);
    }
};
