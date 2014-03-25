class Solution {
public:
    void DFS(int data[], int len, int start, bool &is_reached_end)
    {
        if(start == len -1)
        {
            is_reached_end = true;
            return;
        }
        int max_jump = data[start];
        for(int i = 1; i <= max_jump; i++)
        {
            if(is_reached_end){ break;} //start + i >= len 不会发生
            DFS(data, len, start+i, is_reached_end);
        }
    }
    bool canJump(int A[], int n) {
        bool is_reached_end = false;
        DFS(A, n, 0, is_reached_end);
        return is_reached_end;
    }
};
