/*
思路：
既然最多只能完成两笔交易，而且交易之间没有重叠，那么就divide and conquer。
设i从0到n-1，那么针对每一个i，看看在prices的子序列[0,...,i][i,...,n-1]上分别取得的最大利润（第一题）即可。
这样初步一算，时间复杂度是O(n^2)。

进行优化：
对于点j+1，求price[0..j+1]的最大profit时，很多工作是重复的，在求price[0..j]的最大profit中已经做过了。
类似于Best Time to Buy and Sell Stock，可以在O(1)的时间从price[0..j]推出price[0..j+1]的最大profit,即maxEndWith[j+1]。
但是如何从price[j..n-1]推出price[j+1..n-1]？反过来思考，我们可以用O(1)的时间由price[j+1..n-1]推出price[j..n-1], 即 maxBeginWith[j]。
最终算法：
数组maxEndWith[i]记录了price[0..i]的最大profit，
数组maxBeginWith[i]记录了price[i..n]的最大profit。
已知maxEndWith[i]，求maxEndWith[i+1]是简单的，同样已知maxBeginWith[i]，求maxBeginWith[i-1]也很容易。
最后，我们再用O(n)的时间找出最大的maxEndWith[i]+maxBeginWith[i]，即为题目所求。
*/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int size = prices.size();
        if(size <= 1)
        {
            return 0;
        }
        vector<int> maxEndWith(size);
        int minValue = prices[0];
        for(int i = 1; i < size; ++i)
        {
            if(prices[i] - minValue > maxEndWith[i-1])
            {
                maxEndWith[i] = prices[i] - minValue;
            }
            else
            {
                maxEndWith[i] = maxEndWith[i-1];
                if(prices[i] < minValue)
                {
                    minValue = prices[i];
                }
            }
        }
        
        vector<int> maxBeginWith(size);
        int maxValue = prices[size-1];
        for(int i = size-2; i >=0; --i)
        {
            if(maxValue - prices[i] > maxBeginWith[i+1])
            {
                maxBeginWith[i] = maxValue - prices[i];
            }
            else
            {
                maxBeginWith[i] = maxBeginWith[i+1] ;
                if(prices[i] > maxValue)
                {
                    maxValue = prices[i];
                }
            }
        }
        int maxProfit_ = 0;
        for(int i = 0; i < size-1; ++i)
        {
            if(maxEndWith[i]+maxBeginWith[i] > maxProfit_)
            {
                maxProfit_ = maxEndWith[i]+maxBeginWith[i];
            }
        }
        return maxProfit_;
    }
};
