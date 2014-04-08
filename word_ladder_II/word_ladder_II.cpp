/*
终于过大集合了，哭死了
思路：和word ladder大致相同，BFS。为收集路径，得知道当前节点的父亲节点。注意，当前层的节点可以有多个位于上一层的父节点！
*/
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
    //反向遍历图，把符合要求的路径找出（条件有：1深度，2结尾的字符必须为start word）
    void CollectResult(int cur_depth, string& word, unordered_map<string, vector<string> > &father, vector<string>& tmp, vector<vector<string> > &result)
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
    int BFS(string &start, string &end, unordered_set<string> &dict, unordered_map<string, vector<string> > &father)
    {
        queue<string> words_queue; 
        words_queue.push(start);
        unordered_set<string> visited;//注意，访问起始点！
        visited.insert(start);
        unordered_map<string, int> word_level;
        father[start].push_back("");
        word_level[start] = 0;
        int found_level = INT_MAX;
        while(!words_queue.empty())
        {
            string cur_word = words_queue.front();
            if(word_level[cur_word] > found_level)//如果当前节点的层次大于已找到目标节点的节点层次，则退出
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
                            found_level = word_level[cur_word];//找到目标节点，记录其层次
                        }
                        else if(start.compare(tmp_word) != 0 && dict.count(tmp_word) > 0)
                        {
                            if(visited.count(tmp_word) == 0)
                            {
				father[tmp_word].push_back(cur_word);//如果tmp_word未访问过，则直接添加cur_word为父节点
                                word_level[tmp_word] = word_level[cur_word]+1;
                                words_queue.push(tmp_word);
                                visited.insert(tmp_word);
                            }
			    else
		            {   
				//如果tmp_word已经访问过，如它要添加cur_word为父亲，则要求它的层级比cur_word大，避免两者互为父亲，行成环！
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
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string> > result;
        unordered_map<string, vector<string> > father;//注意，一个节点可以有多个父亲节点！！！
        vector<string> tmp;
        int found_level = BFS(start, end, dict, father); //注意 found_level;
        tmp.push_back(end);
        m_target_depth = found_level+1;
        CollectResult(0, end, father, tmp, result);
        return result;
    }
};
