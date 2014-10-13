/*
思路：
数独规则：每一行、每一列、每一个粗线宫内的数字均含1-9，不重复。
关键是设立标志位。为粗线宫格设置标志位要映射，将9个小宫格映射到
一个一维数组， 即将九宫格内board[i][j]映射到littleBoard[i/3*3+j/3]。
然后再判断是否访问过！

*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int size = board.size();
        vector<vector<bool> > rowMark(size, vector<bool>(size));
        vector<vector<bool> > colMark(size, vector<bool>(size));
        vector<vector<bool> > littleBoard(size, vector<bool>(size));
        
        for(int i = 0; i < size; ++i)
        {
            for(int j = 0; j < size; ++j)
            {
                if(board[i][j] == '.')
                    continue;
                int val = board[i][j]-'0'-1;
                if(!rowMark[i][val] && !colMark[j][val] && 
                !littleBoard[i/3*3+j/3][val])
                {
                    rowMark[i][val] = true;
                    colMark[j][val] = true;
                    littleBoard[i/3*3+j/3][val] = true;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};
