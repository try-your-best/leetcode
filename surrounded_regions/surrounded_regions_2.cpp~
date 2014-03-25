/*
广搜。从上下左右四个边界往里走,凡是能碰到的'O',都是跟边界接壤的,应该删除。深搜的话会由于递归数太大会有runtime error的错误。
*/
#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<fstream>
using namespace std;


struct Point1
{
    int row_posi;
    int col_posi;
    Point1(int x, int y):row_posi(x),col_posi(y){}
    Point1(const Point1& point):row_posi(point.row_posi),col_posi(point.col_posi){}
};
class Solution {
public:
    void BFS(int row_posi, int col_posi, vector<vector<char> > &board, bool** mark)
    {
        int row = board.size();
        int col = board[0].size();
        queue<Point1> points;
        points.push(Point1(row_posi, col_posi));
        mark[row_posi][col_posi] = true;
        while(!points.empty())
        {
            Point1 cur_point = points.front();
            points.pop();
            row_posi = cur_point.row_posi;
            col_posi = cur_point.col_posi;
            if(row_posi-1 >= 0 && board[row_posi-1][col_posi] == 'O' && !mark[row_posi-1][col_posi])//up
            {
                points.push(Point1(row_posi-1, col_posi));
                mark[row_posi-1][col_posi] = true;
            }
            if(col_posi+1 < col && board[row_posi][col_posi+1] == 'O' && !mark[row_posi][col_posi+1])//right
            {
                points.push(Point1(row_posi, col_posi+1));
                mark[row_posi][col_posi+1] = true;
            }
            if(row_posi+1 < row && board[row_posi+1][col_posi] == 'O' && !mark[row_posi+1][col_posi])//down
            {
                points.push(Point1(row_posi+1, col_posi));
                mark[row_posi+1][col_posi] = true;
            }
            if(col_posi-1 >= 0 && board[row_posi][col_posi-1] == 'O' && !mark[row_posi][col_posi-1])//left
            {
                points.push(Point1(row_posi, col_posi-1));
                mark[row_posi][col_posi-1] = true;
            }   
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
            mark[i] = new bool[col](); //记得初始化mark[i]中的元素。如果是mark[i] = new bool[col]，不会初始化。这个错误我error了好多次！
        }
        for(int i = 0; i < col; i++)//lef to right
        {
            if(board[0][i] == 'O' && !mark[0][i])
            {
                BFS(0, i, board, mark);
            }
        }
        if(row >= 2) 
        {
            for(int i = 1; i < row; i++)//up to down
            {
                if(board[i][col-1] == 'O' && !mark[i][col-1])
                {
                    BFS(i, col-1, board, mark);
                }
            }
            if(col >= 2)
            {    
                for(int i = col-2; i >= 0; i--) //right to left
                {
                    if(board[row-1][i] == 'O' && !mark[row-1][i])
                    {
                        BFS(row-1, i, board, mark);
                    }
                }
                if(row >= 3)
                {
                    for(int i = row-2; i >= 1; i--) //down to up
                    {
                         if(board[i][0] == 'O' && !mark[i][0])
                         {
                             BFS(i, 0, board, mark);
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
        delete[] mark;
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
