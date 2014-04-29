/*
思路：模拟加法，注意溢出的情况。
*/
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int len = digits.size();
        if(len == 0)
        {
            return digits;
        }
        int carry = 0;
        digits[len-1]++;
        bool overFlow = false;
        for(int i = len -1; i >= 0; i--)
        {
            int curSum = digits[i] + carry;
            if(curSum >= 10)
            {
               digits[i] = curSum % 10;
               carry = 1;
               if(i == 0)
               {
                   overFlow = true;
               }
            }
            else
            {
                digits[i] = curSum;
                break;
            }
        }
        if(overFlow)
        {
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};
