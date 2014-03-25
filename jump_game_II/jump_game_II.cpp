/*
思路：一开始想到的是用DP。结果超时。看答案才知用贪心！
即每次都选择在当前跳跃次数下，下一步能跳跃到最远的点！
*/
class Solution {
public:
    int jump(int A[], int n) {
        int step_num = 0;//到达当前距离所用的最小跳跃次数。
        int last_reached_distance = 0;//目前跳跃次数下，所能到达的最大距离。
        int next_max_reached_distance = 0;//下一次跳跃所能到达的最大距离。
        for(int i = 0; i < n; i++)
        {
            if(i > last_reached_distance)
            {
                last_reached_distance = next_max_reached_distance;
                step_num++;
            }
            next_max_reached_distance = max(next_max_reached_distance,i+A[i]);
        }
        return step_num;
    }
};
