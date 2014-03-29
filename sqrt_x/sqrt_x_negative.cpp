/*
最直接的做法，超时了
*/
class Solution {
public:
    int sqrt(int x) {
        for(int i = 0; i < x; i++)
        {
            if(i*i == x)
            {
                return i;
            }
            else if(i*i > x)
            {
                return i-1;
            }
        }
    }
};
