/*
思路：用二分查找找平方根。
*/

class Solution {
public:
    int sqrt(int x) {
        if(x < 2) 
        {
            return x;
        }
        int low = 1;
        int high = x / 2;
        int last_mid = -1;//记录最近一次mid
        while(low <= high)
        {
            int mid = (low + high)/2;
            if( x / mid > mid)//注意，不要用 x > mid * mid,会溢出
            {
                low = mid + 1;
                last_mid = mid;//我们要找的是最大mid满足mid^2 <= x;在最后当low与high相邻时，如果 high^2 != x,则我们选择low，即最大的mid;
            }
            else if(x / mid < mid) 

            {
                high = mid - 1;
            }
            else
            {
                return mid;
            }
        }
        return last_mid;
    }
};
