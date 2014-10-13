class Solution {
public:
    vector<vector<bool> > rowMark;
    vector<vector<bool> > colMark;
    vector<vector<bool> > littleBoard;
    void solveSudoku(vector<vector<char> > &board) {
        int size = board.size();
        rowMark = vector<vector<bool> >(size, vector<bool>(size));
        colMark = vector<vector<bool> >(size, vector<bool>(size));
        littleBoard =  vector<vector<bool> >(size, vector<bool>(size));
        DFS(board, 0);
    }
    bool DFS(vector<vector<char> > &board, int index)
    {
        if(index > 80) return true;
        int row = index/9;
        int col = index%9;
        if(board[row][col] != '.')
        {
            char val = board[row][col] - '1';
            if(isValid(row, col, val))
            {
                fill(row, col, val);
                return DFS(board, index+1);
            }
            else return false;
        }
        else
        {
            for(char i = 0; i < 9; ++i)
            {
                if(isValid(row, col, i))
                {
                     board[row][col] = i+'1';
                     fill(row, col, i);
                     if(DFS(board, index+1)) return true;
                     clear(row, col, i);
                }
            }
            board[row][col] = '.';
            return false;
        }
    }
    
    void fill(int row, int col, char val)
    {
        rowMark[row][val] = true;
        colMark[col][val] = true;
        littleBoard[row/3*3+col/3][val] = true;
    }
    
    void clear(int row, int col, char val)
    {
        rowMark[row][val] = false;
        colMark[col][val] = false;
        littleBoard[row/3*3+col/3][val] = false;
    }
    
    bool isValid(int row, int col, char val)
    {
        return (!rowMark[row][val]&&!colMark[col][val]&&!littleBoard[row/3*3+col/3][val]) ? true : false;
    }
};
