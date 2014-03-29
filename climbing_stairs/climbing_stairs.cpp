/*
思路：菲波那契数列
*/
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2)
        {
            return n;
        }
        int pre = 1;
        int cur = 2;
        int next = 0;
        for(int i = 3; i <= n; i++)
        {
            next = cur + pre;
            pre =  cur;
            cur = next;
        }
        return next;
    }
};
