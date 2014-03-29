/*
思路：制造如下的vector
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

第n行数组的长度为n;假设第n行的第i个元素为A[n][i];
则 A[n+1][i+1] = A[n][i]+A[n][i+1];
第一和最后一个元素固定为1;
*/
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > results; 
        if(numRows == 0)
        {
            return results;
        }
        results.push_back(vector<int >(1,1));
        for(int i = 2; i <= numRows; i++)
        {
            vector<int > cur (i,1);
            for(int j = 0; j < i - 2; j++)
            {
                cur[j+1] = results[i-2][j] + results[i-2][j+1];
            }
            results.push_back(cur);
        }
        return results;
    }
};
