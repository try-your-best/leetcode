/*
思路：
数学解法

在n!个排列中，第一位的元素总是(n-1)!一组出现的，也就说如果p = k / (n-1)!，那么排列的最开始一个元素一定是nums[p]。

假设有n个元素，第K个permutation是
a1, a2, a3, .....   ..., an
那么a1是哪一个数字呢？
那么这里，我们把a1去掉，那么剩下的permutation为
a2, a3, .... .... an, 共计n-1个元素。 n-1个元素共有(n-1)!组排列，那么这里就可以知道
设变量K1 = K
a1 = K1 / (n-1)!
同理，a2的值可以推导为
a2 = K2 / (n-2)!
K2 = K1 % (n-1)!
 .......
a(n-1) = K(n-1) / 1!
K(n-1) = K(n-2) /2!
an = K(n-1)
*/
class Solution {
public:
    string getPermutation(int n, int k) {
        int numbers[n];
        int permu_num = 1;
        for(int i = 0; i < n; i++)
        {
            numbers[i] = i+1;
            permu_num *= i+1;
        }
        k--; //注意,k必须自减1,因为 numbers[] 是从0开始的！
        string str = "";
        for(int i = 0; i < n; i++)
        {
            permu_num /= (n-i);
            int selected_index = k / permu_num;
            str += '0' + numbers[selected_index];
            for(int j = selected_index; j < n -1 - i; j++) //注意，selected_index是剩下的未选元素的第selected_index个,顺序是升序。
            {
                numbers[j] = numbers[j+1];
            }
            k = k % permu_num; //更新k的值
        }
        return str;
    }
};
