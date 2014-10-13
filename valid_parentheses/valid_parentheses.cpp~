/*
通过栈去放左符号，如果来了一个右符号，如当前栈顶是一个对应的左符号，则继续。如果栈顶不是
对应的左符号或为空，则不是有效的括号对！

*/

class Solution {
public:
    bool isValid(string s) {
        int size = s.size();
        if(!size) return 0;
        stack<char> lefts;
        for(int i = 0;i < size; ++i)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                lefts.push(s[i]);
            }
            else if(s[i] == ')')
            {
                if(lefts.empty())
                    return false;
                else if(lefts.top() != '(')
                    return false;
                lefts.pop();
            }
            else if(s[i] == '}')
            {
                if(lefts.empty())
                    return false;
                else if(lefts.top() != '{')
                    return false;
                lefts.pop();
            }
            else if(s[i] == ']')
            {
                if(lefts.empty())
                    return false;
                else if(lefts.top() != '[')
                    return false;
                lefts.pop();
            }
        }
        if(lefts.empty())
            return true;
        else
            return false;
    }
};
