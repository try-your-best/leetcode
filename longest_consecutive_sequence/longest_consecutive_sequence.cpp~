/*
思路:因为要O(n)的复杂度，所以在空间上要多耗费一些。遍历列表，
以当前点为中心向左右展开看是否连续，在展开的过程中访问到的点
在以后的列表中就不用在重复访问了，因为相邻的点为了最大长度，
肯定是一起的，不用重复访问
*/

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> existed;
        for(int i = 0; i < num.size(); ++i)
        {
            existed.insert(num[i]);
        }
        unordered_set<int> visited;
        int longest = INT_MIN;
        for(int i = 0; i < num.size(); ++i)
        {
            if(visited.count(num[i]) == 0)
            {
                int len = 1;
                visited.insert(num[i]);
                int var = num[i]-1;
                while(existed.count(var))
                {
                    ++len;
                    visited.insert(var);
                    --var;
                }
                var = num[i]+1;
                while(existed.count(var))
                {
                    ++len;
                    visited.insert(var);
                    ++var;
                }
                longest = max(longest, len);
            }
        }
        return longest;
    }
};
