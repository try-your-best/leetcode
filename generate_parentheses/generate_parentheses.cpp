/*
思路：深搜！！ 
把生成的括号字符串看成一个数组，第一个字符是"("，最后一个是")";
对于中间的每个位置，有两种可能"("或")"。n对括号。
对于"(",只要限制其数量不要超过n; 通过left_num维护;
对于")",确保其前面的位置有足够的"(";通过need_right_num维护。
*/
class Solution {
public:
    void DFS(int left_num, int need_right_num, int depth, int pair_num, string str, vector<string>& results)
    {
        if(depth == pair_num * 2)
        {
            str+=')';
            results.push_back(str);
            return;
        }
        if(left_num < pair_num) //注意边界条件，不是left_num <= pair_num！
        {
            DFS(left_num+1, need_right_num+1, depth+1, pair_num, str+"(", results);
        }
        if(need_right_num > 0)
        {
            DFS(left_num, need_right_num-1, depth+1, pair_num, str+")", results);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> results;
        if(n == 0)
        {
            return results;
        }
        string str("(") ;
        DFS(1, 1, 2, n, str, results);
        return results;
    }
};
