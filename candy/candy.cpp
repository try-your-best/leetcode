/*
用一个数组 candy[n]，表示第 i 个小孩所应该发的最少糖果数
数组 ratings[n] 表示每个小孩的评分
1.从左到右扫描一遍， candy[i] = 1, if ratings[i] <= ratings[i-1] ; 
  candy[i] = candy[i-1] + 1, if ratings[i] > ratings[i-1]
2.从右到左扫描一遍， candy[i] = candy[i], if ratings[i] <= ratings[i+1] ; 
  candy[i] = max(candy[i], candy[i+1] + 1), if ratings[i] > ratings[i+1]
3.对candy[]求和，即得到最小所需糖个数。
这道题用到的思路和Trapping Rain Water是类似的。
*/
class Solution {
public:
    int candy(vector<int> &ratings) {
        vector<int> candies(ratings.size(), 1);
        const int size = ratings.size();
        for(int i = 1; i < size; i++)
        {
            if(ratings[i] > ratings[i-1])
            {
                candies[i] = candies[i-1]+1;
            }
        }
        for(int i = size-2; i >= 0; --i) //note not int i = size-1;
        {
            if(ratings[i] > ratings[i+1])
            {
                candies[i] = max(candies[i], candies[i+1]+1);
            }
        }
        int minCandies = 0;
        for(int i = 0; i < size; ++i)
        {
            minCandies+=candies[i];
        }
        return minCandies;
    }
};
