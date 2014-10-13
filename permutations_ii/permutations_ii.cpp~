/*
思路：在算法1的基础上，当我们枚举第i个位置的元素时，若要把后面第j个元素和i交换，
则先要保证[i…j-1]范围内没有和位置j相同的元素。有以下两种做法：
（1）可以每次在需要交换时进行顺序查找；（2）用哈希表来查重。具体见下面的代码。
因为这个算法的思想就是每次用将当前序列的头元素i与j个元素交换后，再递归的求子序列的全排列，如果
[i…j-1]范围内存和位置j相同的元素，那么剩余子序列的元素就是相同的，所以子序列的全排列也是相同的。
因为头元素相同，所以最终排列会重复！！！

注意不要误以为以下两种做法能够去重：
（1）最开始先对数组进行排序，以后每次交换时，只要保证当前要交换的元素和前一个元素不同，这种做法是错误的，
虽然开始进行了排序，但是元素的交换会使数组再次变的无序
（2）每次进入递归函数permuteRecur时，对从当前索引开始的子数组排序，这种做法也是错误的，因为每次交换元素后，
我们要恢复交换的元素，如果在递归函数内排序，就不能正确的恢复交换的元素。 
参考：
http://www.cnblogs.com/tenosdoit/p/3662644.html
*/
class Solution {
public:
    vector<vector<int> > result;
    void permuteCore(vector<int>& num, int start)
    {
        int len = num.size();
        if(start == len)
        {
           result.push_back(num);
           return;
        }
        unordered_set<int> umap;
        for(int i = start; i < len; ++i)
        {
			if(umap.count(num[i]))
			{
				continue;
			}
			umap.insert(num[i]);
            swap(num[start], num[i]);
            permuteCore(num, start+1);
            swap(num[start], num[i]);
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        result.clear();
        permuteCore(num, 0);
        return result;
    }
};
