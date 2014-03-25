/*
思路：遍历数组，如果当前元素值为0,则检查能否越过。如果不为0,则访问下一个值。
一开始是用DFS做的，可惜优化后还是超时，原因是判断路径不可达花费的时间太长。
遇到元素值为0，而进行递归回溯时，存在大量的对点的重复访问。而遍历数组的方法对点的判断只进行一次。
*/
class Solution {
public:
    bool CanSkip(int data[], int cur_position)
    {
        
        for(int i = cur_position-1; i >= 0; i--)
        {
            if(i+data[i] > cur_position)
            {
                return true;
            }
        }
        return false;
    }
    bool canJump(int A[], int n) {
        for(int i = 0; i < n-1; i++)//注意，是n-1而不是n，如果到达最后一个元素，就不用检查它的值是否为0了
        {
            if(A[i] == 0)
            {
                if(!CanSkip(A, i))
                {
                    return false;
                }
            }
        }
        return true;
    }
};
