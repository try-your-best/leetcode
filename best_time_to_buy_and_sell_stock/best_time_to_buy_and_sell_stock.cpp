/*
思路：maxValue[j] 表示从点j到n时刻股票的最大值，
所以maxValue[j]-prices[j]就能得到j时刻最大的差价。
*/
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int size = prices.size();
        if(size <= 1)
        {
            return 0;
        }
        vector<int> maxValue(size);
        maxValue[size-1] = prices[size-1];
        for(int j = size-2; j >=0; --j)
        {
            if(prices[j] > maxValue[j+1])
                maxValue[j] = prices[j];
            else
                maxValue[j] = maxValue[j+1];
        }
        int maxProfit_ = INT_MIN;
        for(int i = 0; i < size-1; ++i)
        {
            if(maxValue[i]-prices[i] > maxProfit_)
            {
                maxProfit_ = maxValue[i]-prices[i];
            }
        }
        return maxProfit_;
    }
};
