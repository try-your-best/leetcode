/*
思路：anagram 就是组成字符串的字符和个数相同，但位置不同。如 eat 和 ate 。
所以首先对字符串按字符顺序排序（将eat 和 ate 都变为 ate），将排序的字符串作为map的key进行分组！
参考答案：http://discuss.leetcode.com/questions/227/anagrams
*/
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> results;
        map<string, vector<string> > dict;
        vector<string> :: iterator iter;
        for(iter = strs.begin(); iter != strs.end(); iter++)
        {
            string key = *iter;
            sort(key.begin(), key.end());//对字符进行排序！
            dict[key].push_back(*iter);//通过map分组！
        }
        map<string, vector<string> > :: iterator map_iter;
        for(map_iter = dict.begin(); map_iter != dict.end(); map_iter++)
        {
            if(map_iter->second.size() > 1)
            {
                for(iter = map_iter->second.begin(); iter != map_iter->second.end(); iter++)
                {
                    results.push_back(*iter);
                }
            }
        }
        return results;
    }
};
