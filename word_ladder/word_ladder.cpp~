/*
思路：当边的权值相等时，可以用BFS求单源最短径。
这到题目的关键是如何遍历当前节点的边。有两种方式
1、遍历字典，找出符合要求的单词（即字符相差1的单词）。参考 word_ladder_2.cpp
2、根据当前单词，逐位改变字符，再到字典里找是否有符合要求的单词。
前者适合字典的单词长度长，个数少的情况。后者适合字典单词长度短，个数多的情况。
本题用方法1会超时!顾用方法2。
*/
class Solution {
public:
    void Swap(char& a, char& b)
    {
        if(a == b)
            return;
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
    int BFS(string start, string end, unordered_set<string> &dict)
    {
        queue<string> str_queue;
        str_queue.push(start);
        unordered_set<string> visited;//节点的访问标志
        map<string, int> str_to_len; //记录当前节点与源节点的距离
        str_to_len[start] = 1;
        while(!str_queue.empty())
        {
            string current_str(str_queue.front());
            string new_str(current_str);
            str_queue.pop();
            int cur_len = current_str.size();
            for(int i = 0; i < cur_len; i++)
            {
                for(char tmp = 'a'; tmp <= 'z'; tmp++)
                {
                    if(tmp == new_str[i])
                    {
                        continue;
                    }
                    else
                    {
                        Swap(tmp, new_str[i]);
                        if(new_str == end)
                        {
                            return str_to_len[current_str]+1;
                        }
                        else if(dict.count(new_str) > 0 && !visited.count(new_str))//遍历当前节点的边。
                        {
                            str_queue.push(new_str);
                            visited.insert(new_str);
                            str_to_len[new_str] = str_to_len[current_str]+1;
                        }
                        Swap(tmp, new_str[i]);
                    }
                }
            }
        }
        return 0;
    }
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if(start.compare(end)== 0)
        {
            return 1;
        }
        else
        {
            return BFS(start, end, dict);
        }
    }
};
