/*
比较无聊的一道题。解题点就在于清空标志位存在哪里的问题。可以创建O(m+n)的数组来存储，
但此题是希望复用已有资源。这里可以选择第一行和第一列来存储标志位。

1.先确定第一行和第一列是否需要清零
2.扫描剩下的矩阵元素，如果遇到了0，就将对应的第一行和第一列上的元素赋值为0
3.根据第一行和第一列的信息，已经可以讲剩下的矩阵元素赋值为结果所需的值了
4.根据1中确定的状态，处理第一行和第一列。
*/
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int row = matrix.size();
        if(!row) return;
        int col = matrix[0].size();
        bool zeroRow = false;
        bool zeroCol = false;
        for(int i = 0; i < row; ++i)
        {
            if(matrix[i][0] == 0)
            {
                zeroRow = true;
                break;
            }
        }
        for(int i = 0; i < col; ++i)
        {
            if(matrix[0][i] == 0)
            {
                zeroCol = true;
                break;
            }
        }
        
        for(int i = 1; i < row; ++i)
        {
            for(int j =1; j < col; ++j)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < row; ++i)
        {
            for(int j = 1; j < col; ++j)
            {
                if(matrix[i][0] == 0 ||  matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        if(zeroRow)
            for(int i = 0; i < row; ++i)
                matrix[i][0] = 0;
        if(zeroCol)
            for(int i = 0; i < col; ++i)
                matrix[0][i] = 0;
    }
};
