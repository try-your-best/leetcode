/*
直接用递归来深搜，但是当测试数据上到250*250矩阵后，直接递归导致的空间太大直接runtime error。然后改为用个Stack来搜索就ac了。
*/
#include<iostream>
#include<vector>
#include<fstream>
#include<string>
using namespace std;

class Solution {
public:
    void DFS(int row_posi, int col_posi, vector<vector<char> > &board, bool** mark)
    {
        int row = board.size();
        int col = board[0].size();
        mark[row_posi][col_posi] = true;
        if(row_posi-1 >= 0 && board[row_posi-1][col_posi] == 'O' && !mark[row_posi-1][col_posi])//up
        {
            DFS(row_posi-1,  col_posi, board, mark);
        }
        if(col_posi+1 < col && board[row_posi][col_posi+1] == 'O' && !mark[row_posi][col_posi+1])//right
        {
            DFS(row_posi, col_posi+1, board, mark);
        }
        if(row_posi+1 < row && board[row_posi+1][col_posi] == 'O' && !mark[row_posi+1][col_posi])//down
        {
            DFS(row_posi+1, col_posi, board, mark);
        }
        if(col_posi-1 >= 0 && board[row_posi][col_posi-1] == 'O' && !mark[row_posi][col_posi-1])//left
        {
            DFS(row_posi, col_posi-1, board, mark);
        }
    }
    void solve(vector<vector<char> > &board) {
        int row = board.size();
        if(row == 0) 
            return;
        int col = board[0].size();
        bool **mark = new bool *[row];
        for(int i = 0; i < row; i++)
        {
            mark[i] = new bool[col];
        }
        for(int i = 0; i < col; i++)//lef to right
        {
            if(board[0][i] == 'O' && !mark[0][i])
            {
                DFS(0, i, board, mark);
            }
        }
        if(row >= 2) 
        {
            for(int i = 1; i < row; i++)//up to down
            {
                if(board[i][col-1] == 'O' && !mark[i][col-1])
                {
                    DFS(i, col-1, board, mark);
                }
            }
            if(col >= 2)
            {    
                for(int i = col-2; i >= 0; i--) //right to left
                {
                    if(board[row-1][i] == 'O' && !mark[row-1][i])
                    {
                        DFS(row-1, i, board, mark);
                    }
                }
                if(row >= 3)
                {
                    for(int i = row-2; i >= 1; i--) //down to up
                    {
                         if(board[i][0] == 'O' && !mark[i][0])
                         {
                             DFS(i, 0, board, mark);
                         }
                    } 
                }
            }
        }
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(!mark[i][j])
                {
                    board[i][j] = 'X';
                }
            }
        }
        for(int i = 0; i < row; i++)
        {
            delete[] mark[i];
        }
    }
};

void Test()
{
   ifstream fin("file.in"); 
   ofstream fout("file.out");
   string str;
   vector<vector<char> > boards;
   while(fin >> str)
   {
        vector<char> tmp(str.c_str(), str.c_str()+str.length());
        boards.push_back(tmp);
   }
   int a =  boards.size();
   int b = boards[0].size();
   cout << boards.size() << endl;
   cout << boards[0].size() << endl;
   Solution s;
   s.solve(boards);
   int row = boards.size();
   for(int i = 0; i < row; i++)
   {
        string tmp_str(boards[i].begin(), boards[i].end());
        fout << tmp_str << endl;
   }
}

int main()
{
    Test();
    return 0;
}
