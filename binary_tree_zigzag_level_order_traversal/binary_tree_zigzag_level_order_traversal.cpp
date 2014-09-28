/*
思路：广度遍历二叉树。通过map区分层数。同时通过表示toLeft判别顺序！
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
    void BFS(TreeNode *root, vector<vector<int> >& result)
    {
        queue<TreeNode*> nodes;
        map<TreeNode*, int> levels;
        vector<int> tmp;
        nodes.push(root);
        levels[root] = 1;
        bool  = true;
        while(!nodes.empty())
        {
            TreeNode* cur = nodes.front();
            nodes.pop();
            tmp.push_back(cur->val);
            if(nodes.empty() || levels[cur] < levels[nodes.front()]) 
            {
                if(toLeft)
                {
                    result.push_back(tmp);
                    toLeft = false;
                }
                else
                {
                    reverse(tmp.begin(), tmp.end());
                    result.push_back(tmp);
                    toLeft = true;
                }
                tmp.clear();
            }
            if(cur->left)
            {
                nodes.push(cur->left);
                levels[cur->left] = levels[cur]+1;
            }
            if(cur->right)
            {
                nodes.push(cur->right);
                levels[cur->right] = levels[cur]+1;
            }
        }
        
    }
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if(!root)
            return result;
        BFS(root, result);
        return result;
    }
};
