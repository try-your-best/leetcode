/*
思路：深搜加剪枝就通过了，证明leetcode上测试数据的n比较小。
关键是在判断是否已有其它皇后在同一列，上斜和下斜时，
通过映射的方法将判断的时间复杂度控制为O(1); 
此题给我更深的教训是，leetcode上写的程序的所有测试用例都在一个main函数
里面，所以慎用全局变量，它只会初始化的一次！
*/


#include<iostream>
using namespace std;

const int MAX = 13;
//设 row 为行号，col 为列号
bool column[MAX]; // (row, col) -> col
bool down_diagonal[MAX*2]; //(row, col) -> row - col + MAX
bool up_diagonal[MAX*2];//(row, col) -> row + col
int solution_num = 0;

class Solution {
private:
    void DFS(int row, int col, int n)
    {
        column[col] = true;
        down_diagonal[row - col + MAX] = true;
        up_diagonal[row+col] = true;
        if(row == n - 1)
        {
            solution_num++;
            return;
        }
        //update row
        row++;
        for(int i = 0; i < n; i++)
        {
            if(!column[i] && !down_diagonal[row-i+MAX] && !up_diagonal[row+i])
            {
                DFS(row , i, n);
                column[i] = false;
                down_diagonal[row - i + MAX] = false;
                up_diagonal[row + i] = false;
            }
        }
    }
public:
    int totalNQueens(int n) {
        solution_num = 0;//复位！！！
        for(int i = 0; i < n; i++)
        {
             DFS(0, i, n);
             //记得复位！！
             column[i] = false;
             down_diagonal[0-i+MAX] = false;
             up_diagonal[i] = false;
        }
        return solution_num;
    }
};

int main()
{
    Solution s;
    cout <<  s.totalNQueens(4) << endl;
    return 0;
}
