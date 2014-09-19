/*
思路：升买降卖。
知道下个节点要升，如果没有股票，则买。
知道下个节点要降，如果有股票，则卖。
*/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int size = prices.size();
        if(size <= 1)
            return 0;
        int profit = 0;
        int start = 0;
        bool keep = false;
        int i = 0;
        for(; i < size-1; ++i)
        {
            if(prices[i] <= prices[i+1])
            {
                if(!keep)
                {
                    keep = true;
                    start = prices[i];
                }
            }
            else
            {
                if(keep)
                {
                    profit += (prices[i] - start);
                    keep = false;
                }
            }
        }
        if(keep)
        {
            profit += (prices[i] - start);
        }
        return profit;
    }
};
