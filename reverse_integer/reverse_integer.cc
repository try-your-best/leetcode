/*
思路：先将x转化正数，然后通过求余截位，最后反转！负数的话，求余反转不好处理符号位。一次A掉！
额外思考：
Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?
Throw an exception? Good, but what if throwing an exception is not an option? You would then have to re-design the function (ie, add an extra parameter).
*/
class Solution {
public:
    int error;
    int reverse(int x) {
        bool is_positive = true;
        if(x < 0)
        {
            is_positive = false;
        }
        long long tmp = x;//要先转为long long，避免x是INT_MIN。int的值域不是对称的！
        if(!is_positive)
        {
            tmp *= -1;
        }
        long long reverse = 0;
        while(tmp > 0)
        {
            reverse = reverse * 10 + tmp % 10;
            tmp /= 10;
        }
        if(is_positive)
        {
            if(reverse > INT_MAX)//判断反转值是否有效！
            {
                error = -1;
            }
        }
        else
        {
            reverse *= -1;
            if(reverse < INT_MIN)
            {
                error = -1;
            }
        }
        return reverse;
    }
};
