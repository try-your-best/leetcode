/*
思路：最多选两次，每次都选择和前点最大价差的点。
这种算法是有误的。例如以下序列：
Input:	[6,1,3,2,4,7]
Output:	6
Expected: 7
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
        vector<int> indexOfMax(size);
        maxValue[size-1] = prices[size-1];
        indexOfMax[size-1] = size-1;
        for(int j = size-2; j >=0; --j)
        {
            if(prices[j] > maxValue[j+1])
            {
                maxValue[j] = prices[j];
                indexOfMax[j] = j;
            }
            else
            {
                maxValue[j] = maxValue[j+1];
                indexOfMax[j] = indexOfMax[j+1];
            }
        }
        vector<int> diff(size);
        diff[size-1] = 0;
        for(int j = size-2; j>=0; --j)
        {
            if(maxValue[j] - prices[j] > diff[j+1])
            {
                diff[j] = maxValue[j] - prices[j];
            }
            else
            {
                diff[j] = diff[j+1];
            }
        }
        int maxProfit_  = INT_MIN;
        for(int i = 0; i < size; i++)
        {
            int profit = maxValue[i] - prices[i] + diff[indexOfMax[i]];
            maxProfit_ = max(maxProfit_, profit);
        }
        return maxProfit_;
    }
};
