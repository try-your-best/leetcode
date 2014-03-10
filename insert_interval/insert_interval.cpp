#include<iostream>
#include<vector>

using namespace std;

//Last executed input:	[[1,5],[6,8]], [5,6]
//Time Limit Exceeded
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

struct PositionInfo
{
    int m_index;
    int m_value;
    PositionInfo(int index, int value):m_index(index),m_value(value){}
    PositionInfo(const PositionInfo& element)
    {
        m_index = element.m_index;
        m_value = element.m_value;
    }
};
 
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
struct PositionInfo
{
    int m_index;
    int m_value;
    PositionInfo(int index, int value):m_index(index),m_value(value){}
    PositionInfo(const PositionInfo& element)
    {
        m_index = element.m_index;
        m_value = element.m_value;
    }
};
 
class Solution {
private:
    PositionInfo GetStartInfo(vector<Interval>& intervals, int start)
    {
        int low = 0;
        int high = intervals.size() - 1;
        int index = 0;
        int value = 0;
        while(low <= high)
        {
            int middle = (high + low)/2; //注意，不要写成 middle = (high - low)/2
            if(start >= intervals[middle].start && start <= intervals[middle].end)
            {
                index = middle;
                value = intervals[middle].start;
                break;
            }
            else if(start < intervals[middle].start)
            {
                high = middle -1;
            }
            else
            {
                low = middle+1;
            }
        }
        if(low > high) //注意这特殊条件
        {
            index = low; // low 有可能等于 intervals.size()
            value = start;
        }
        return PositionInfo(index, value);
    }
    
    PositionInfo GetEndInfo(vector<Interval>& intervals, int end)
    {
        int low = 0;
        int high = intervals.size() - 1;
        int index = 0;
        int value = 0;
        while(low <= high)
        {
            int middle = (high + low)/2;
            if(end >= intervals[middle].start && end <= intervals[middle].end)
            {
                index = middle;
                value = intervals[middle].end;
                break;
            }
            else if(end < intervals[middle].start)
            {
                high = middle -1;
            }
            else
            {
                low = middle+1;
            }
        }
        if(low > high)
        {
            index = high; //可能出现-1
            value = end;
        }
        return PositionInfo(index, value);
    }
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> final_intervals;
        if(intervals.empty())
        {
            final_intervals.push_back(newInterval);
            return final_intervals;
        }
        PositionInfo start_info = GetStartInfo(intervals, newInterval.start);
        PositionInfo end_info = GetEndInfo(intervals, newInterval.end);
        if(start_info.m_index >= intervals.size()) // newInterval 出现在最后
        {
            for(int i = 0; i < intervals.size(); i++)
            {
                final_intervals.push_back(intervals[i]);
            }
            final_intervals.push_back(newInterval);
        }
        else if(end_info.m_index < 0) // newInterval 出现在最前
        {
            final_intervals.push_back(newInterval);
            for(int i = 0; i < intervals.size(); i++)
            {
                final_intervals.push_back(intervals[i]);
            }
        }
        else if(end_info.m_index < start_info.m_index) // newInterval不覆盖其它interval
        {
            for(int i = 0; i <= end_info.m_index; i++)
            {
                final_intervals.push_back(intervals[i]);
            }
            final_intervals.push_back(newInterval);
            for(int i = start_info.m_index; i < intervals.size(); i++)
            {
                final_intervals.push_back(intervals[i]);
            }
        }
        else 
        {
             for(int i = 0; i < start_info.m_index; i++) // newInterval 覆盖后被包含在一个或多个interval
             {
                 final_intervals.push_back(intervals[i]);
             }
             final_intervals.push_back(Interval(start_info.m_value, end_info.m_value));
             for(int i = end_info.m_index+1; i < intervals.size(); i++)
             {
                 final_intervals.push_back(intervals[i]);
             }
        }
        return final_intervals;
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
    Interval a(1,5);
    Interval b(6,8);
    intervals.push_back(a);
    intervals.push_back(b);
    Interval new_interval(5,6);
    Print(intervals);
    Solution s;
    vector<Interval> result = s.insert(intervals, new_interval);
    Print(result);
}
