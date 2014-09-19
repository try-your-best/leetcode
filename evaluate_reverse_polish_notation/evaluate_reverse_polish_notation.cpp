/*
思路：使用栈处理后缀表达式.
*/

class Solution {
public:
    bool isOperator(char str)
    {
      switch(str)
      {
       case '(':
       case ')':
       case '+':
       case '-':
       case '*':
       case '/':
           return true;
       default :
           return false;
       }
    }
    int evalRPN(vector<string> &tokens) {
        stack<int> nums;
        for(size_t i = 0; i < tokens.size(); ++i)
        {
		// tokens[i].size() ==1 为了防止出现负数的情况。tokens[i].size()>1, tokens[i]必然不是符号。        	
		if(tokens[i].size() ==1 && isOperator(tokens[i][0]))
        	{
        		int num1 = nums.top();//由于是弹栈，注意num1和num2的顺序！num2应在表达式的前方！
        		nums.pop();
        		int num2 = nums.top();
        		nums.pop();
        		switch(tokens[i][0])
        		{
        			case '+':
        				num2 += num1;
        				break;
        			case '-':
        				num2 -= num1;
        				break;
        			case '*':
        				num2 *= num1;
        				break;
        			case '/':
        				num2 /= num1;
        				break;
        		}
        		nums.push(num2);
        	}
        	else
        	{
        		nums.push(atoi(tokens[i].c_str()));
        	}
        }
        return nums.top();
    }
};
