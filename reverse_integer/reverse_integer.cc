/*
˼·���Ƚ�xת��������Ȼ��ͨ�������λ�����ת�������Ļ������෴ת���ô������λ��һ��A����
����˼����
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
        long long tmp = x;//Ҫ��תΪlong long������x��INT_MIN��int��ֵ���ǶԳƵģ�
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
            if(reverse > INT_MAX)//�жϷ�תֵ�Ƿ���Ч��
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
