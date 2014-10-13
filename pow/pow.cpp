/*
思路：注意区分指数和底数为0的特殊情况。以及指数为正和负数的情况。
在计算时要避免重复计算！
*/

class Solution {
public:
    double powUnsign(double x, unsigned int n)
    {
        if(n == 1) return x;
        double tmp = powUnsign(x, n >> 1);
        if(n & 1)
        {
            return tmp*tmp*x;
        }
        else
        {
            return tmp*tmp;
        }
    }
    double pow(double x, int n) {
        if(x-0 < 0.000001 && x-0 > -0.000001)
            return 0;
        if(n == 0)
            return 1;
        if(n > 0)
        {
            return powUnsign(x, n);
        }
        else
        {
            return 1/powUnsign(x, -n);
        }
    }
};
