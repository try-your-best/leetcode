/*
思路：对区间的起点进行排列，升序。遍历区间集合，合并区间。
当前一个区间的end大与后一个区间的start时，合并区间。
这道题可以原集合上操作，也可以新建集合。
但是有个测试用例涉及大量区间的合并，如果采用前者，会涉及大量的销毁操作，回超时。
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool CompareIntervalStart(Interval inter1, Interval inter2)
{
    return (inter1.start <  inter2.start); //改成inter1.start <=  inter2.start 在某个test会出错，发出信号SIGSEGV。
}

class Solution {
public:
    int Max(int a, int b){ return a >= b ? a : b; }
    
    vector<Interval> merge(vector<Interval> &intervals) {
        if(intervals.size() == 0)
            return intervals;
        vector<Interval> results;
        sort(intervals.begin(), intervals.end(), CompareIntervalStart);
        int start = intervals[0].start; 
        int end = intervals[0].end;
        int len = intervals.size();
        for(int i =1; i < len; i++)
        {
            if(intervals[i].start <= end)
            {
                end = Max(end, intervals[i].end);
            }
            else
            {
                results.push_back(Interval(start, end));
                start = intervals[i].start;
                end = intervals[i].end;
            }
        }
        results.push_back(Interval(start, end)); //添加最后一个区间
        return results;
    }
};

