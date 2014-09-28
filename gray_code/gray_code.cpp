/*
找规律：
gray code中文名叫格雷码，一看题就知道是模拟类型，写几个例子出来找规律。
以3位格雷码为例。
0 0 0
0 0 1
0 1 1
0 1 0

1 1 0
1 1 1
1 0 1
1 0 0
可以看到第n位的格雷码由两部分构成，一部分是n-1位格雷码，另一部分是 1<<(n-1)和n-1位格雷码逆序的和组成。
*/

class Solution {
public:
    vector<int> result;
    vector<int> grayCode(int n) {
        result.clear();
        createGrayCode(n);
        return result;
    }
    
    void createGrayCode(int n)
    {
        if(n == 0)
        {
            result.push_back(0);
            return;
        }
        createGrayCode(n-1);
        int size = result.size();
        int offset = 1 << (n-1);
        for(int i = size-1; i >= 0; --i)
        {
            result.push_back(result[i]+ offset);
        }
    }
    
};
