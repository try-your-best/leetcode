/*
思路：序列无序，且有重复元素！找到和为target的两个数，并返回其下标。
复制数组，排序，转化为有序的two sum 问题，找到和为target的两个数后，
再在原数组找到对应的下标
*/
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> results;
        int size = numbers.size();
        if(size == 0)
        {
            return results;
        }
        vector<int> new_numbers(numbers);
        sort(new_numbers.begin(), new_numbers.end());
        int index1 = 0;
        int index2 = size-1;
        while(index1 < index2)
        {
            if(new_numbers[index1] + new_numbers[index2] == target)
            {
                break;
            }
            else if(new_numbers[index1] + new_numbers[index2] > target)
            {
                index2--;
            }
            else
            {
                index1++;
            }
        }
        int final_index1 = -1;
        int final_index2 = -1;
        int i = 0;
        for(; i < size; i++)
        {
            if(numbers[i] == new_numbers[index1] || numbers[i] == new_numbers[index2])
            {
                final_index1 = i+1;
                break;
            }
        }
        i++;
        for(; i < size; i++)
        {
            if(numbers[i] == new_numbers[index1] || numbers[i] == new_numbers[index2])
            {
                final_index2 = i+1;
                break;
            }
        }
        results.push_back(final_index1);
        results.push_back(final_index2);
    }
};
