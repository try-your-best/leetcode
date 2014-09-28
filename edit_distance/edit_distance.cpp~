/*
思路：
对于编辑距离，当我们要计算d(i,j)时，即计算A(i)到B(j)之间的编辑距离，此时，设A(i)形式是somestr1c；B(i)形如somestr2d的话，
将somestr1变成somestr2的编辑距离已知是d(i-1,j-1)
将somestr1c变成somestr2的编辑距离已知是d(i,j-1)
将somestr1变成somestr2d的编辑距离已知是d(i-1,j)
那么利用这三个变量，就可以递推出d(i,j)了：
如果c==d，显然编辑距离和d(i-1,j-1)是一样的
如果c!=d，情况稍微复杂一点，
如果将c替换成d，编辑距离是somestr1变成somestr2的编辑距离 + 1，也就是d(i-1,j-1) + 1
如果在c后面添加一个字d，编辑距离就应该是somestr1c变成somestr2的编辑距离 + 1，也就是d(i,j-1) + 1
如果将c删除了，那就是要将somestr1编辑成somestr2d，距离就是d(i-1,j) + 1
那最后只需要看着三种谁最小，就采用对应的编辑方案了。
递推公式出来了：
dp[i][j] =  dp[i-1][j-1]   if (A[i] == B[j]) or = min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]) +1;
初始条件： dp[0][j] = j and dp[i][0] = i  
参考文章：
http://fisherlei.blogspot.com/2012/12/leetcode-edit-distance.html 
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.size() < word2.size())
            word1.swap(word2);
        string& bigStr = word1;
        string& smallStr = word2;
        int sSize = smallStr.size();
        int bSize = bigStr.size();
        vector<int> cur(sSize+1);
        vector<int> prev(sSize+1);
        for(int i = 0; i <= sSize; i++)
            prev[i] = i; //pre[0][i];
        for(int i = 1; i <= bSize;  ++i)
        {
            cur[0] = i; // cur[i][0]
            for(int j = 1; j <= sSize; ++j)
            {
                if(bigStr[i-1] == smallStr[j-1])
                {
                    cur[j] = prev[j-1] ;
                }
                else
                {
                    cur[j] = min(prev[j], prev[j-1]);
                    cur[j] = min(cur[j], cur[j-1]) + 1;
                }
            }
            prev = cur;
        }
        return cur[sSize];
    }
};
