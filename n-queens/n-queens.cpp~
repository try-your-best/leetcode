/*
思路：关键的方法是设置标志位。判断是否在同一斜行。一次AC。
*/

class Solution {
public:
    vector<bool> leftUp;
    vector<bool> rightUp;
    vector<bool> colMark;
    vector<string> tmpResult;
    vector<vector<string> > result;
    int row;
    int col;
    void DFS(int depth)
    {
        if(depth == row)
        {
            result.push_back(tmpResult);
            return;
        }
        for(int i = 0; i < col; ++i)
        {
            if(!colMark[i] && !leftUp[depth-i+row] && !rightUp[depth+i])
            {
                colMark[i] = true;
                leftUp[depth-i+row] = true;
                rightUp[depth+i] = true;
                tmpResult[depth][i] = 'Q';
                DFS(depth+1);
                colMark[i] = false;
                leftUp[depth-i+row] = false;
                rightUp[depth+i] = false;
                tmpResult[depth][i] = '.';
            }
        }
    }
    
    vector<vector<string> > solveNQueens(int n) {
        leftUp = vector<bool> (2*n);
        rightUp = vector<bool> (2*n);
        colMark = vector<bool> (n);
        tmpResult =  vector<string> (n, string(n, '.'));
        result.clear();
        row = col = n;
        DFS(0);
        return result;
        
    }
};
