/*
思路：先缓存每两个下标所能组成的和及其下标（a,b），然后在两个for循环遍历数组,这是下标为（c,d），
利用缓存值求出所需的4sum，即(a,b,c,d)。(a,b),(c,d)首先不能有交集，
然后在存4sum的时要用set去除重！即（num[a],num[b],num[c],num[d]）;
时间O(n^3),空间O(n^2)
*/
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        int num_size = num.size();
        if(num_size <= 3)
        {
            return vector<vector<int> >();
        }
        sort(num.begin(), num.end());
        map<int, vector<pair<int, int> > > cache;
        for(int i = 0; i < num_size; i++)
        {
            for(int j = i+1; j < num_size; j++)
            {
                cache[num[i]+num[j]].push_back(pair<int, int>(i, j));//保存组合和的下标而不是值！
            }
        }
        set<vector<int> > result;
        for(int i = 0; i < num_size; i++)
        {
            for(int j = i+1; j < num_size; j++)
            {
                int key = target-num[i]-num[j];
                if(cache.find(key) != cache.end())
                {
                    int cur_key_size = cache[key].size();
                    for(int k = 0; k < cur_key_size; k++)
                    {
                        int first_index = cache[key][k].first;
                        if(j >= first_index)//(i, j)与(first, second)有重合。注意边界条件，是">="
                        {
                            continue;
                        }
                        result.insert(vector<int>{num[i], num[j], num[first_index], num[cache[key][k].second]});
                    }
                }
            }
        }
        return vector<vector<int> >(result.begin(), result.end());
    }
};s
