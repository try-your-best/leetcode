/*
思路：多画几个图，找出规律;一次A掉。
假设有加油站 0,1,2,3,4； 找出可以环绕加油站一圈的起点。
如果0无法到3,则，从1或2出发也无法到3。这时候满足条件的起点在3,或4;
选择起点后，记录其通过加油站的个数pass_gas_num，达到要求则返回起点。
*/
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int gas_size = gas.size();
        int total_size = gas_size*2;
        int start = 0;
        int cur_gas = 0;
        int pass_gas_num = 0;
        for(int i = 0; i < total_size; i++)
        {
           cur_gas += gas[i%gas_size];
           if(cur_gas >= cost[i%gas_size])
           {
               cur_gas -= cost[i%gas_size];
               pass_gas_num++;
               if(pass_gas_num == gas_size)
               {
                   return start;
               }
           }
           else
           {
               start = i+1;
               if(start >= gas_size)
               {
                   return -1;
               }
               pass_gas_num = 0;
               cur_gas = 0;
           }
        }
    }
};
