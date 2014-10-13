/*
题目描述的不是很清楚，其实就是第i+1个字符串是第i个字符串的读法，第1字符串为 “1”,第2个字符串就是
第1个的读法，即“11”，比如第四个字符串是1211，它的读法是 1个1、1个2,2个1，因此第五个字符串是111221。

简单的模拟就可以。

其实我们可以发现字符串中永远只会出现1,2,3这三个字符，假设第k个字符串中出现了4，
那么第k-1个字符串必定有四个相同的字符连续出现，假设这个字符为1，则第k-1个字符串为x1111y。
第k-1个字符串是第k-2个字符串的读法，即第k-2个字符串可以读为“x个1,1个1,1个y” 或者“*个x,1个1,1个1,y个*”，
这两种读法分别可以合并成“x+1个1,1个y” 和 “*个x，2个1，y个*”，代表的字符串分别是“(x+1)11y” 和 "x21y"，
即k-1个字符串为“(x+1)11y” 或 "x21y"，不可能为“x1111y”.
*/

class Solution {
public:
    string countAndSay(int n) {
        if(n <= 0) return string();
        string prev("1");
        for(int i = 1; i < n; ++i)
        {
            char curChar = prev[0];
            int times = 1;
            prev+='#'; //添加结束标志，以便最后一组有效的字符能被统计！
            int prevSize = prev.size();
            string result;
            for(int j = 1; j < prevSize; ++j)
            {
                if(prev[j] == curChar)
                {
                    times++;
                }
                else
                {
                    result+= (char)('0'+times);
                    result+=curChar;
                    curChar = prev[j];
                    times = 1;
                }
            }
            prev = result;
        }
        return prev;
    }
};
