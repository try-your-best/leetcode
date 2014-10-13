class Solution {
public:
    void add(char& a, char b, char& carry)
    {
        if((a^carry) == 0) // 注意 ^ 的优先级比 == 低！！
        {
            if(a == '1')
            {
                a = '0';
                carry = '1';
            }
        }
        else
        {
            a = '1';
            carry = '0';
        }
        if((a^b) == 0)
        {
            if(a == '1')
            {
                a = '0';
                carry = '1';
            }
        }
        else
        {
            a = '1';
            //carry = '0' //note 不要重复处理 carry
        }
    }
    string addBinary(string a, string b) {
        if(a.size() < b.size())
            a.swap(b);
        string& big = a;
        string& small = b;
        int size1 = big.size();
        int size2 = small.size();
        char carry = '0';
        for(int i = 1; i <= size1; ++i)
        {
            if( i <= size2)
            {
                add(big[size1-i], small[size2-i], carry);
            }
            else
            {
                if(carry == '1')
                {
                    add(big[size1-i], '0', carry);
                }
                else
                    break;
            }
        }
        if(carry == '1')
        {
            return string("1") + big;
        }
        else
        {
            return big;
        }
    }
};
