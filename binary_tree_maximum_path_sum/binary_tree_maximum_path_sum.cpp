/*
参考答案：
可以利用“最大连续子序列和”问题的思路,见第 §13.2节。如果说 Array 只有一个方向的话,
那么 Binary Tree 其实只是左、右两个方向而已,我们需要比较两个方向上的值。
不过,Array 可以从头到尾遍历,那么 Binary Tree 怎么办呢,我们可以采用 Binary Tree 最常用
的 dfs 来进行遍历。先算出左右子树的结果 L 和 R,如果 L 大于 0,那么对后续结果是有利的,我们
加上 L,如果 R 大于 0,对后续结果也是有利的,继续加上 R。


自己理解：
对于每个节点有4种选择，
自己节点的值，
加上左子树最大和，
加上右子树最大和，
选择左或右子树，为父节点做准备。
时间复杂度 O(n),空间复杂度 O(logn)
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
    int max_sum;
    int DFS(TreeNode *p_node)
    {
        if(p_node == NULL)
        {
            return 0;
        }
        int left_max_sum = DFS(p_node->left);
        int right_max_sum = DFS(p_node->right);
        int sum = p_node->val;//选择当前节点，加上左树，或者加上右子树;
        if(left_max_sum > 0)
        {
            sum+= left_max_sum;
        }
        if(right_max_sum > 0)
        {
            sum+= right_max_sum;
        }
        max_sum = max(max_sum, sum);
        return max(left_max_sum, right_max_sum) > 0 ? max(left_max_sum, right_max_sum)+p_node->val : p_node->val;//两个子树只能选择一个方向！
    }
public:
    int maxPathSum(TreeNode *root) {
        if(root == NULL)
        {
            return 0;
        }
        max_sum = INT_MIN;
        DFS(root);
        return max_sum;
    }
};
