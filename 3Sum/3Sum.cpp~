/*
思路：将3sum转化为2sum。在枚举第一个数字时，从左到右，不要重复。
对选定的第一个数的后面的数进行2sum。在2sum时，对num[low]和num[high]，
每次都是找不重复的下一个！
我们可以在 2sum问题 的基础上来解决3sum问题，假设3sum问题的目标是target。每次从数组中选出一个数k，
从剩下的数中求目标等于target-k的2sum问题。这里需要注意的是有个小的trick：当我们从数组中选出第i数时，
我们只需要求数值中从第i+1个到最后一个范围内字数组的2sum问题。
参考文章：http://www.cnblogs.com/tenosdoit/p/3649607.html
*/
class Solution {
public:
    vector<vector<int> > result;
    vector<vector<int> > threeSum(vector<int> &num) {
        int size = num.size();
        if(size == 0) return result;
        result.clear();
        sort(num.begin(), num.end());
        for(int i = 0; i < size-2; ++i)
        {
            if(i == 0 || num[i] != num[i-1])
            {
                twoSum(num, i+1, num[i]);
            }
        }
        return result;
    }
    void twoSum(vector<int>& num, int start, int one)
    {
        vector<int> tmp;
        tmp.push_back(one);
        int target = 0 - one;
        int low = start;
        int high = num.size()-1;
        while(low < high)
        {
            if(num[low]+num[high] == target)
            {
                tmp.push_back(num[low]);
                tmp.push_back(num[high]);
                result.push_back(tmp);
                tmp.pop_back();
                tmp.pop_back();
                do
                {
                    low++;
                }while(low < high && num[low] == num[low-1]);//找不重复的下一个
            }
            else if(num[low]+num[high] > target)
            {
                do
                {
                    high--;
                }while(low < high && num[high] == num[high+1]);//找不重复的下一个
            }
            else
            {
                do
                {
                    low++;
                }while(low < high && num[low] == num[low-1]);//找不重复的下一个

            }
        }
    }
};
