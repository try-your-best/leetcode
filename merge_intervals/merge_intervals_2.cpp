#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

//Definition for an interval.
struct Interval 
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};


bool CompareIntervalStart(Interval inter1, Interval inter2)
{
    return (inter1.start <  inter2.start); //为什么用 <= 会有bug
}

class Solution {
public:
    int Max(int a, int b){ return a >= b ? a : b; }
    
    vector<Interval> merge(vector<Interval> &intervals) {
        if(intervals.size() == 0)
            return intervals;
        sort(intervals.begin(), intervals.end(), CompareIntervalStart);
        vector<Interval> :: iterator iter_cur = intervals.begin();
        vector<Interval> :: iterator iter_post = iter_cur;
        iter_post++;
        while(iter_post != intervals.end())
        {
            cout << iter_cur->start << " " << iter_cur->end<< endl;
            cout << iter_post->start << " " << iter_post->end<< endl;
            if(iter_cur->end >= iter_post->start)
            {
                iter_cur->end = Max(iter_cur->end, iter_post->end);
                iter_post = intervals.erase(iter_post);
            }
            else
            {
                iter_cur++;
                iter_post++;
            }
        }
        return intervals;
    }
};

void Print(vector<Interval> intervals)
{
    int len = intervals.size();
    for(int i = 0; i < len; i++)
    {
        //if(i > 30){ break;}
        cout << intervals[i].start <<" "<< intervals[i].end<<",";
    }
    cout << endl;
}

void Test()
{
   ifstream fin("file.in"); 
   int start = 0; int end = 0;
   vector<Interval> intervals;
   while (fin >> start && fin >> end)
   {
        intervals.push_back(Interval(start, end));
   }
   cout << intervals.size() << endl;
   //Print(intervals);
   Solution s;
   Print(s.merge(intervals));
}

int main()
{
    Test();
    return 0;
}
