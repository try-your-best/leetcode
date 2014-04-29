#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<climits>
#include<fstream>
using namespace std;


void Print(vector<vector<string> > &result)
{
    int row = result.size();
    for(int i = 0; i < row; i++)
    {
        int column = result[i].size();
        for(int j = 0; j < column; j++)
        {
            cout << result[i][j] << ",";
        }
        cout << endl;
    }
}

void PrintFather(vector<string>  father)
{
    for(int i = 0; i < father.size(); i++)
    {
        cout << father[i] << ",";
    }
    cout << endl;
}

class Solution {
private:
    int m_target_depth;
public:
    void Swap(char& a, char &b)
    {
        if(&a == &b)
        {
            return;
        }
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
    
    void CollectResult(int cur_depth, string& word, map<string, vector<string> > &father, vector<string>& tmp, vector<vector<string> > &result)
    {
        if(cur_depth == m_target_depth)
        {
            if(father[word][0].compare("") == 0)
            {
                result.push_back(tmp);
            }
            return; 
        }
        int father_size =  father[word].size();
        for(int i = 0; i < father_size; i++)
        {
            tmp.insert(tmp.begin(), father[word][i]);
            string haha = father[word][i];
            CollectResult(cur_depth+1, haha, father, tmp, result);
            tmp.erase(tmp.begin());
        }
    }
    int BFS(string &start, string &end, set<string> &dict, map<string, vector<string> > &father)
    {
        queue<string> words_queue; 
        words_queue.push(start);
        set<string> visited;//ע�⣬������ʼ�㣡
        visited.insert(start);
        map<string, int> word_level;
        father[start].push_back("");
        word_level[start] = 0;
        int found_level = INT_MAX;
        while(!words_queue.empty())
        {
            string cur_word = words_queue.front();
            if(word_level[cur_word] > found_level)
            {
                break;
            }
            words_queue.pop();
            int word_len = cur_word.length();
            string tmp_word = cur_word;
            for(int i = 0; i < word_len; i++)
            {
                for(char cur_char = 'a'; cur_char <= 'z'; cur_char++)
                {
                    if(cur_char == tmp_word[i])
                    {
                        continue;
                    }
                    else
                    {
                        Swap(cur_char, tmp_word[i]);
                        if(tmp_word.compare(end) == 0)
                        {
                            father[end].push_back(cur_word);
                            found_level = word_level[cur_word];
                        }
                        else if(start.compare(tmp_word) != 0 && dict.count(tmp_word) > 0)
                        {
                            if(visited.count(tmp_word) == 0)
                            {
				father[tmp_word].push_back(cur_word);
                                word_level[tmp_word] = word_level[cur_word]+1;
                                words_queue.push(tmp_word);
                                visited.insert(tmp_word);
                            }
			    else
		            {
                                if(word_level[tmp_word] > word_level[cur_word])
                                {
                                    father[tmp_word].push_back(cur_word);
                                }
                            }
                        }
                        Swap(cur_char, tmp_word[i]);
                    }
                }
            }
        }
        return found_level;
    }
    vector<vector<string> > findLadders(string start, string end, set<string> &dict) {
        vector<vector<string> > result;
        map<string, vector<string> > father;
        vector<string> tmp;
        int found_level = BFS(start, end, dict, father); //ע�� found_level;
        tmp.push_back(end);
//        cout << found_level << endl;
//        PrintFather(father[start]);
        m_target_depth = found_level+1;
        CollectResult(0, end, father, tmp, result);
        return result;
    }
};


void Test()
{
   string start = "hot";
   string end = "dog";
   set<string> dict;
   dict.insert("hot");
   dict.insert("dog");
   dict.insert("dot");
   Solution s;
   s.findLadders(start, end, dict);
}

void Test1()
{
    string start;
    string end; 
    set<string> dict;
    ifstream fin("file.in");
    fin >> start;
    fin >> end;
    string tmp;
    while(fin >> tmp)
    {
        dict.insert(tmp);
    }
    Solution s;
    vector< vector<string> > result = s.findLadders(start, end, dict);
    Print(result);
}

int main()
{
    Test1();
    return 0;
}