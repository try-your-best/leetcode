/*
思路：深搜， 在深搜的过程中注意判断选中的字符串是否符合要求。
当选中的字符串长度为1,则该字符串一定有效，
如果长度为2,则注意其起始值不能为0,即出现'01'
如果长度为3,则注意其起始值不能为0，同时该值必须不大于255。
下面是参考别人的精简代码！！！
*/
class Solution {
public:
    void DFS(string &str, int start, int step, string ip,vector<string>& results)
    {
        int str_len = str.size();
        if(start == str_len && step == 4)// 找到一个合法解
        {
            ip.resize(ip.size()-1);
            results.push_back(ip);
            return;
        }
        if(str_len - start > 3 * (4-step))
        {
            return; // 剪枝
        }
        if(str_len - start < 4 -step)
        {
            return; // 剪枝
        }
        int num = 0;
        for(int i = start; i < start+3; i++)
        {
            num = num*10 + (str[i]-'0');
            if(num <= 255)// 当前结点合法,则继续往下递归
            {
                ip += str[i];
                DFS(str, i+1, step+1, ip+".", results);
            }
            if(num == 0) break;  // 不允许前缀 0,但允许单个 0
        }
    }
    vector<string> restoreIpAddresses(string s) {
        string ip;
        vector<string> results;
        int str_len = s.length();
        if(str_len < 4 || str_len > 12)
        {
            return results;
        }
        DFS(s, 0, 0, ip, results);
        return results;
    }
};
