class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int row = matrix.size();
        if(!row) return false;
        int col = matrix[0].size();
        int low = 0; 
        int high = row * col -1;
        while(low <= high)
        {
            int mid = (low + high)/2;
            int x = mid / col;
            int y = mid % col;
            if(matrix[x][y] == target)
            {
                return true;
            }
            else if(matrix[x][y] > target)
            {
                high = mid -1;
            }
            else
            {
                low = mid + 1;
            }    
        }
        return false;
    }
};
