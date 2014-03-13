//思路：首先是了解题目2Sum的思路（参考剑指offer题目41）。
//要对序列进行排序，所以最低的复杂度是O(nlog(n))。
//然后从序列头开始每次选中一元素 num[i]，然后用2Sum对 num[i+1...high] 进行处理。找到与期望值差距最小的和。
//2Sum的复杂度是O(n), 所以3SumClosest的复杂度是O(n^2)。注意不是O(n^2 * logn)。因为两个处理步骤是顺序的。
//当然，2Sum如何能保证找到合适的解，目前缺乏严格的数学证明，继续寻找中。。。
//最简单的做法是3个循环，复杂度为O(n^3)
class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int len = num.size();
        int sum = 0;
        sort(num.begin(), num.end());
        int closest = 0x7fffffff; //注意，不要把该参考变量放到for循环内！
        for(int i = 0; i < len - 2; i++)
        {
            int low = i + 1;
            int high = len - 1;
            int expectation = target - num[i];
            while(low < high)
            {
                int diff = expectation - num[low] - num[high];
                if(abs(closest) > abs(diff))
                {
                    closest = diff;
                    sum = target - diff;
                }
                if(diff == 0)
                {
                    return sum;
                }
                else if(diff > 0)//当前的sum太小
                {
                    low++;
                }
                else //当前的sum太大
                {
                    high--;
                }
            }
        }
        return sum;
    }
};
