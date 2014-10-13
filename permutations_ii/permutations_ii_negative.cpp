#include <limits.h>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > result;
    void permuteCore(vector<int>& num, int start)
    {
        int len = num.size();
        if(start == len)
        {
           result.push_back(num);
           return;
        }
        for(int i = start; i < len; ++i)
        {
            if(i > start && num[start] == num[i])
                continue;
            swap(num[start], num[i]);
            permuteCore(num, start+1);
            swap(num[start], num[i]);
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        result.clear();
        permuteCore(num, 0);
        return result;
    }
};

void print(const vector<vector<int> > & result)
{
	for(int i = 0; i < result.size(); ++i)
	{
		for(int j = 0; j < result[i].size(); ++j)
		{
			cout << result[i][j] << ",";
		}
		cout << endl;
	}
}

void test()
{
	vector<int> num;
	num.push_back(1);
	num.push_back(1);
	num.push_back(2);
	Solution s;
	print(s.permuteUnique(num));
}

int main()
{
	test();
	return 0;
}

