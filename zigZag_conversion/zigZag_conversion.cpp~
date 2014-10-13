/*
思路：
题目的意思是把字符串上下上下走之字形状,然后按行输出,比如包含数字0~22的字符串, 给定行数为5,走之字形如下:
现在要按行输出字符,即:0 8 16 1 7 9 15 17 2…….
如果把以上的数字字符看做是字符在原数组的下标, 给定行数为n = 5, 可以发现以下规律:
(1)第一行和最后一行下标间隔都是interval = n*2-2 = 8 ;         
(2)中间行的间隔是周期性的,第i行的间隔是: interval–2*i,  2*i,  interval–2*i, 2*i, interval–2*i, 2*i, …

参考：http://www.cnblogs.com/TenosDoIt/p/3738693.html
*/

class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows == 0 || nRows == 1) //note，注意特例！！！
            return s;
        string result;
        int size = s.size();
        for(int i = 0; i < size; i += 2*nRows-2)
        {
            result.push_back(s[i]);
        }
        for(int i = 1; i < nRows-1; ++i)
        {
        	int n = i;
        	int m = i+(2*nRows-2*(i+1));
        	while(n < size)
        	{
        		result.push_back(s[n]);
        		if(m < size)
        		{
        			result.push_back(s[m]);
        		}
        		n += 2*nRows-2;
        		m += 2*nRows-2;
        	}
        }
        for(int i = nRows-1; i < size; i += 2*nRows-2)
        {
            result.push_back(s[i]);
        }
        return result;
    }
};
