/*
˼·��n*n�ľ������Ͻǵ�����Ϊ(start, start),���½ǵ�����Ϊ(end, end);������������ȥȷ��ÿһ����ת��Ȧ��
�� end - stat > 1 ��4������ end - start == 1 ʱ��3������ end == start һ��������ͼ�Ϳ��ú�����ˣ�
*/

class Solution {
private:
    //row > 2 and column > 2
    void SpiralWithNormalSize(vector<vector<int>>& matrix, int start, int end, int& cur_value)
    {
        for(int i = start; i <= end; i++) // left to right
        {
            matrix[start][i] = cur_value;
            cur_value++;
        }
        for(int i = start+1; i <= end; i++) // up to down
        {
            matrix[i][end] = cur_value;
            cur_value++;
        }
        for(int i = end -1; i >= start; i--) // right to left
        {
            matrix[end][i] = cur_value; //ע���±��λ�ò�ҪŪ�� matrix[i][end] 
            cur_value++;
        }
        for(int i = end -1; i >= start + 1; i--) // down to up�����һ��Ҫע����ʼ��
        {
            matrix[i][start] = cur_value;
            cur_value++;
        }
    }
    void SpiralWithSize4(vector<vector<int>>& matrix, int start, int& cur_value)
    {
        matrix[start][start] = cur_value++;
        matrix[start][start+1] = cur_value++;
        matrix[start+1][start+1] = cur_value++;
        matrix[start+1][start] = cur_value++;
    }
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int>> matrix;
        for(int i =0; i < n; i++)
        {
            vector<int> initial(n, 0);
            matrix.push_back(initial);
        }
        int  stop_index = (n-1)/2;
        int insert_value = 1;
        for(int start = 0; start <= stop_index; start++)
        {
            int end = n - 1 - start; 
            if(end - start > 1)
            {
                SpiralWithNormalSize(matrix, start, end, insert_value);
            }
            else if(end - start == 1)
            {
                SpiralWithSize4(matrix, start, insert_value);
            }
            else if(end == start)
            {
                matrix[start][start] = insert_value;
            }
        }
        return matrix;
    }
};
