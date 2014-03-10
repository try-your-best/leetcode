//这种方法简洁，不过会超时。


#include<iostream>
#include<vector>

using namespace std;

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 

 struct Interval{
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };

class Solution {
private:
    int Max(int a, int b){ return a > b ? a : b; }
    int Min(int a, int b){ return a < b ? a : b; }

public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval>::iterator iter = intervals.begin();
        while(iter != intervals.end())
        {
            if(newInterval.end < iter->start)
            {
                intervals.insert(iter, newInterval);
                return intervals;
            }
            else if(newInterval.start > iter->end)
            {
                iter++;
                continue;
            }
            else
            {
                newInterval.start = Min(newInterval.start, iter->start);
                newInterval.end = Max(newInterval.end, iter->end) ;
                iter = intervals.erase(iter); // 注意erase的用法
            }
        }
        intervals.push_back(newInterval);
        return intervals;
    }
};

void Print(vector<Interval>& result)
{
    int len = result.size();
    for(int i = 0; i < len; i++)
    {
        cout << result[i].start << " " << result[i].end << ",";
    }
    cout << endl;
}

int main()
{
    vector<Interval> intervals;
    const int NUM = 20000;
    for(int i = 1; i < NUM; i++)
    {
        intervals.push_back(Interval(i,i+1));    
    }
//    Interval a1(1,2);
//    Interval a2(3,4);
//    Interval a3(5,6);
//    Interval a4(7,10);
//    Interval a5(12,16);
//    intervals.push_back(a1);
//    intervals.push_back(a2);
//    intervals.push_back(a3);
//    intervals.push_back(a4);
//    intervals.push_back(a5);
    Interval new_interval(0,20001);
    //Print(intervals);
    cout << intervals[intervals.size()-1].end << endl;
    Solution s;
    vector<Interval> result = s.insert(intervals, new_interval);
    Print(result);
}

