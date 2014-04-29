/*
思路：不能用乘、除和取模,那剩下的,还有加、减和位运算。
最简单的方法,是不断减去被除数。在这个基础上,可以做一点优化,每次把被除数翻倍,从而加速。
时间O(log(n)),空间O(1);
参考leetcode详解！
*/
#include<iostream>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long a = dividend >= 0 ? dividend : -(long long)dividend;//注意-(long long)dividend，先拓展再转型，防止INT_MIN;
        long long b = divisor >= 0 ? divisor : -(long long) divisor;
        long long result = 0;
        while(a >= b)
        {
            long long c = b;
            for(int i = 0; a >= c; ++i, c <<= 1)//c <<= 1每循环一次，c翻倍。注意不要写成c <<= i。
            {
                a -= c;
                result += 1 << i;//加上对应的个数！
            }
        }
        return ((dividend ^ divisor)>>31) ? -result : result;//(dividend ^ divisor)>>31判断结果是否为0;
    }
};

void Test()
{
	Solution s;
	cout << s.divide(2147483647, 1) << endl;
}

int main()
{
	Test();
	return 0;
}
