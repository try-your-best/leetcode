/*
思路：树是图的一种特殊形式，所以本题可用BFS。
关键点是要记录节点层次变更的时刻。
在提交代码前记得用运行自己的测试用例。
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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > level_order;
        if(root == NULL)
        {
            return level_order;
        }
        queue<TreeNode*> nodes_queue;
        map<TreeNode*, int> map_to_level; //记录节点的层次
        nodes_queue.push(root);
        map_to_level[root] = 0;
        vector<int> same_level_values;
        int cur_level = 0;//记录节点层次的变更
        while(!nodes_queue.empty())
        {
            TreeNode *p_current = nodes_queue.front();
            nodes_queue.pop();
            if(map_to_level[p_current] > cur_level)
            {
                level_order.push_back(same_level_values);
                same_level_values.clear();
                cur_level = map_to_level[p_current];
            }
            same_level_values.push_back(p_current->val);
            
            if(p_current->left != NULL)
            {
                nodes_queue.push(p_current->left);
                map_to_level[p_current->left] = map_to_level[p_current]+1;
            }
            if(p_current->right != NULL)
            {
                nodes_queue.push(p_current->right);
                map_to_level[p_current->right] = map_to_level[p_current]+1;
            }
        }
        level_order.push_back(same_level_values); //收集最后一层！
        return level_order;
    }
};
