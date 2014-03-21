/*
˼·�����ߵ�Ȩֵ���ʱ��������BFS��Դ��̾���
�⵽��Ŀ�Ĺؼ�����α�����ǰ�ڵ�ıߡ������ַ�ʽ
1�������ֵ䣬�ҳ�����Ҫ��ĵ��ʣ����ַ����1�ĵ��ʣ����ο� word_ladder_2.cpp
2�����ݵ�ǰ���ʣ���λ�ı��ַ����ٵ��ֵ������Ƿ��з���Ҫ��ĵ��ʡ�
ǰ���ʺ��ֵ�ĵ��ʳ��ȳ��������ٵ�����������ʺ��ֵ䵥�ʳ��ȶ̣�������������
�����÷���1�ᳬʱ!���÷���2��
�����Ƿ���1��
*/
#include<iostream>
#include<set>
#include<map>
#include<string>
#include<queue>
#include<fstream>
using namespace std;

class Solution {
public:
    bool DiffOneInStrings(string first, string second)
    {
        int len = first.length();
        int diff = 0;
        for(int i = 0; i < len; i++)
        {
            if(first[i] != second[i])
            {
                diff++;
                if(diff > 1)
                {
                    return false;
                }
            }
        }
        if(diff == 1)
            return true;
        else
            return false;
    }
    int BFS(string start, string end, set<string> &dict) //unordered_set<string> &dict
    {
        queue<string> str_queue;
        str_queue.push(start);
        set<string> visited;
        map<string, int> str_to_len;
        str_to_len[start] = 1;
        while(!str_queue.empty())
        {
            string current_str = str_queue.front();
            str_queue.pop();
            for(set<string> :: iterator iter = dict.begin(); iter != dict.end(); iter++)
            {
                if(visited.count(*iter) == 0 && DiffOneInStrings(*iter, current_str))
                {
                    if(DiffOneInStrings(*iter, end))
                    {
                        return str_to_len[current_str]+2;
                    }
                    str_queue.push(*iter);
                    str_to_len[*iter] = str_to_len[current_str]+1;
                    visited.insert(*iter);
                }
            }
        }
        return 0;
    }
    int ladderLength(string start, string end, set<string> &dict) {
        if(start.compare(end)== 0)
        {
            return 1;
        }
        else if(DiffOneInStrings(start, end))
        {
            return 2;
        }
        else
        {
            return BFS(start, end, dict);
        }
    }
};

void Test()
{
    string str1("hit"); 
    string str2("cog");
    set<string> dict;
    dict.insert(string("hot"));
    dict.insert(string("dot"));
    dict.insert(string("dog"));
    dict.insert(string("lot"));
    dict.insert(string("log"));
    Solution s;
    int len = s.ladderLength(str1, str2, dict);
    cout << len << endl;
}

void Test1()
{
    ifstream fin("file.in");
    string start;
    string end;
    fin >> start;
    fin >> end;
    start = "ab";
    end = "ab";
    if(start == end)
        cout << "1" << endl;
//    cout << start << " " << end <<endl; 
    string tmp;
    set<string> dict;
    while(fin >> tmp)
    {
        dict.insert(tmp);
    }
    Solution s;
    int len = s.ladderLength(start, end, dict);
    cout << len << endl;
}

int main()
{
    Test1();
    return 0;
}
