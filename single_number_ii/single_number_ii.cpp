
/*
 * single_number_ii.cpp
 *
 *  Created on: Sep 14, 2014
 *      Author: damonhao
 */
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int singleNumber(int A[], int n) {
        const int BIT_NUM = sizeof(int)*8;
        vector<int> count(BIT_NUM);
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < BIT_NUM; ++j)
            {
                if(A[i] & (1 << j))
                {
                    count[j] = (count[j]+1)%3;
                }
            }
        }
        int result = 0;
        for(int j = 0; j < BIT_NUM; ++j)
        {
            result += (count[j] << j);
        }
        return result;
    }
};

void test1()
{
	Solution s;
	int A[] = {2,2,3,2};
	cout << s.singleNumber(A, sizeof(A)/sizeof(int)) << endl;
}

int main()
{
	test1();
	return 0;
}
