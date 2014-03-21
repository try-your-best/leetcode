/*
思路：回文一般就是从字符串的两头对称的判断是否相等。本题通过除和余运算来实现。
//Do this without extra space. 这句话的意思是说空间复杂度为O(1);
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
        {
            return false;
        }
        int divisor = 1;
        while( x / divisor >= 10){ divisor *= 10; }
        while(x != 0 && x / divisor == x % 10 ) //当 x== 0 时， divisor == 0 
        {
            x %= divisor;
            x /= 10;
            divisor /= 100;
        }
        if(x == 0)
            return true;
        else 
            return false;
    }
};
