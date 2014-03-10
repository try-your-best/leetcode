//思路： 剑指offer里有。细节题，4次才A掉。
//将收集矩形元素分为4个步骤。
class Solution {
private:
void FirstStep(int row_start, int col_start, int col_end, vector<vector<int>> &matrix,vector<int>& spiral_order)
{
    for(int i = col_start; i <= col_end; i++)
        spiral_order.push_back(matrix[row_start][i]);
}

void SecondStep(int row_start, int row_end, int col_end, vector<vector<int>> &matrix,vector<int>& spiral_order)
{
    for(int i = row_start+1; i <= row_end; i++)
        spiral_order.push_back(matrix[i][col_end]);
}

void ThirdStep(int row_end, int col_start, int col_end, vector<vector<int>> &matrix,vector<int>& spiral_order)
{
    for(int i = col_end -1; i >= col_start; i--)
        spiral_order.push_back(matrix[row_end][i]);
}

void FourthStep(int row_start, int row_end, int col_start, vector<vector<int>> &matrix,vector<int>& spiral_order)
{
    for(int i = row_end - 1; i >= row_start + 1; i--) //注意 i 的上界和下界！
        spiral_order.push_back(matrix[i][col_start]);
}

public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> spiral_order;
        int row = matrix.size();
        if(row == 0)
            return spiral_order;
        int col = matrix[0].size();
        int start = 0; //在起始点，行号和列号总是相同。注意不要写成两个for循环！
        while((start <= (row-1)/2) && (start <= (col-1)/2))
        {
            int row_end = row - 1 - start;
            int col_end = col -1 - start;
            FirstStep(start, start, col_end, matrix, spiral_order);//只要矩形不为空，就有第一步
            if(row_end - start >= 1)
            {
                SecondStep(start, row_end, col_end, matrix, spiral_order);
                if(col_end - start >= 1)// 有第二步才有第三步
                {
                   ThirdStep(row_end, start, col_end, matrix, spiral_order);
                   if(row_end - start >= 2)//有第二、三步才有第四步
                   {
                       FourthStep(start, row_end, start, matrix, spiral_order);
                   }
                }
            }
            start++;
        }
        return spiral_order;
    }
};
