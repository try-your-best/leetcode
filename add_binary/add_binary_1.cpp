/*
思路：主要是 add()函数的改变！这种处理加法的方式更简便！
*/

class Solution {
public:
    void add(char& a, char b, int& carry)
    {
        int sum = a - '0' + b - '0' + carry;
        a = '0' + sum % 2;
        carry = sum / 2;
    }
    string addBinary(string a, string b) {
        if(a.size() < b.size())
            a.swap(b);
        string& big = a;
        string& small = b;
        int size1 = big.size();
        int size2 = small.size();
        int carry = 0;
        for(int i = 1; i <= size1; ++i)
        {
            if( i <= size2)
            {
                add(big[size1-i], small[size2-i], carry);
            }
            else
            {
                if(carry == 1)
                {
                    add(big[size1-i], '0', carry);
                }
                else
                    break;
            }
        }
        if(carry == 1)
        {
            return string("1") + big;
        }
        else
        {
            return big;
        }
    }
};
