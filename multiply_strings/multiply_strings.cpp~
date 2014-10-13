/*
参考：
首先我们把每一位相乘，得到一个没有进位的临时结果，如图中中间的一行红色数字就是临时结果，
然后把临时结果从低位起依次进位。对于一个m位整数乘以n位整数的结果，最多只有m+n位。

另外更高效的计算大整数乘法一般有：（1）karatsuba算法，复杂度为3nlog3≈3n1.585，
可以参考百度百科、面试题——大整数乘法、乘法算法-Karatsuba算法。
（2）基于FFT(快速傅里叶变换)的算法，复杂度为o(nlogn), 可以参考FFT, 卷积, 多项式乘法, 大整数乘法

http://www.cnblogs.com/TenosDoIt/p/3735309.html
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        int size1 = num1.size();
        int size2 = num2.size();
        if(size1 == 0 || size2 == 0)
            return string();
        int finalSize = size1+size2;
        vector<int> tmp(finalSize);
        for(int i = size2-1; i >= 0; --i)
        {
            for(int j = size1-1; j >= 0; --j)
            {
                tmp[i+j+1] += (num2[i]-'0')*(num1[j]-'0');
            }
        }
        string result(finalSize, '0');
        result[finalSize-1] = tmp[finalSize-1]%10 + '0';
        for(int i = finalSize-2; i >= 0; --i)
        {
            tmp[i] += tmp[i+1]/10;
            result[i] = tmp[i]%10 + '0';
        }
        int start = 0;
        int end = result.size();
        while(result[start] == '0' && start < end-1)//终止条件为start < end-1而不是start < end是为了防止结果为0的情况！
        {
            ++start;
        }
        return result.substr(start, result.size()-start+1);
    }
};
