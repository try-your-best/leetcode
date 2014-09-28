/*
思路：用 expect[i] 做哈希表去统计字符串T中字符i的个数，然后再
用cur[i]去统计在S的当前子串中包含T中的字符i的个数。curSize 则是子串包含
T中字符的个数。如果 curSize == T.size() 则说明子串包含T中所有的字符。
维护一个窗口，假设窗口的起始和结束是start和end。end先从左往右遍历
扩大窗口，直到curSize == T.size()。然后在右移start缩小窗口，在此过程中不断计算
最小子串，直到curSize < T.size()。然后开始下一轮扩大窗口！
注意 T中的字符串可能有重复的，如 aab， S是aabb，输出是aab。
复杂读 O(n)
我自己想到的O(n^2)
参考：http://huntfor.iteye.com/blog/2083485
*/



class Solution {
public:
    string minWindow(string S, string T) {
        int tSize = T.size();
        vector<int> expect(256);
        for(int i = 0; i < tSize; ++i)
        {
            expect[T[i]]++;
        }
        int curSize = 0;
        int strSize = S.size();
        vector<int> cur(256);
        int lastStart = 0;
        int minStart = 0;
        int minEnd = 0;
        int minLen = INT_MAX;
        for(int i = 0; i < strSize; i++)
        {
            if(expect[S[i]] > 0)
            {
                if(cur[S[i]] < expect[S[i]])
                {
                    ++curSize;
                }
                cur[S[i]]++;
                if(curSize == tSize)
                {
                    int tmpStart = lastStart;
                    while(curSize == tSize)
                    {
                        if(minLen > i-tmpStart+1)
                        {
                            minStart = tmpStart;
                            minEnd = i;
                            minLen = i-tmpStart+1;
                        }
                        if( expect[S[tmpStart]] == 0)
                        {
                            ++tmpStart;
                        }
                        else
                        {
                            --cur[S[tmpStart]];
                            if(cur[S[tmpStart]] < expect[S[tmpStart]])
                            {
                                lastStart = ++tmpStart;
                                curSize--;
                            }
                            else
                            {
                            	++tmpStart;
                            }
                        }
                    }
                }
            }
        }
        if(minLen == INT_MAX)
        {
            return string();
        }
        else
        {
            return S.substr(minStart, minEnd-minStart+1);
        }
    }
};
