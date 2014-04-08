/*
思路：变形的深搜，用depth限制搜索的深度，用set<pair<int, int> > mark_set记录已添加的位置，避免重复访问！
*/
class Solution {
private:
    set<pair<int, int> > mark_set;
public:
    void DFS(vector<vector<char> > &board, int row, int col, int depth, string &word, bool &is_found)
    {
        int word_len = word.size();
        if(depth == word_len)
        {
            is_found = true;
            return;
        }
        int board_row = board.size();
        int board_col = board[0].size();
        //up
        if(!is_found && row-1 >= 0 && board[row-1][col] == word[depth] && mark_set.count(pair<int, int>(row-1, col)) == 0)
        {
            mark_set.insert(pair<int, int>(row-1, col));
            DFS(board, row-1, col, depth+1, word, is_found);
            mark_set.erase(pair<int, int>(row-1, col));
        }
        //right
        if(!is_found && col+1 < board_col && board[row][col+1] == word[depth] && mark_set.count(pair<int, int>(row, col+1)) == 0)
        {
            mark_set.insert(pair<int, int>(row, col+1));
            DFS(board, row, col+1, depth+1, word, is_found);
            mark_set.erase(pair<int, int>(row, col+1));
        }
        //down
        if(!is_found && row+1 < board_row && board[row+1][col] == word[depth] && mark_set.count(pair<int, int>(row+1, col)) == 0)
        {
            mark_set.insert(pair<int, int>(row+1, col));
            DFS(board, row+1, col, depth+1, word, is_found);
            mark_set.erase(pair<int, int>(row+1, col));
        }
        //left
        if(!is_found && col-1 >= 0 && board[row][col-1] == word[depth] && mark_set.count(pair<int, int>(row, col-1)) == 0)
        {
            mark_set.insert(pair<int, int>(row, col-1));
            DFS(board, row, col-1, depth+1, word, is_found);
            mark_set.erase(pair<int, int>(row, col-1));
        }
    }
    bool exist(vector<vector<char> > &board, string word) {
        int board_row = board.size();
        int board_col = board[0].size();
        bool is_found = false;
        for(int i = 0; i <board_row; i++)
        {
            for(int j= 0; j < board_col; j++)
            {
                if(board[i][j] == word[0])
                {
                    mark_set.insert(pair<int, int>(i, j));//添加标志!
                    DFS(board, i, j, 1, word, is_found);
                    if(is_found)
                    {
                        return true;
                    }
                    mark_set.erase(pair<int, int>(i, j));//删除标志。把 mark_set操作放在 DFS()外可确保删除的是已添加的标志！
                }
            }
        }
        return false;
    }
};
