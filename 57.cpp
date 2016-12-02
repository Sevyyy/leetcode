/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ans;
        int n = intervals.size();
        if(n == 0) 
        {
            ans.push_back(newInterval);
            return ans;
        }
        int i = 0;
        while(i < n)
        {
            if(newInterval.end < intervals[i].start)
            {
                ans.push_back(newInterval);
                while(i < n)
                {
                    ans.push_back(intervals[i]);
                    i ++;
                }
                return ans;
            }
            else if(newInterval.start > intervals[i].end)
                ans.push_back(intervals[i]);

            else
            {
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
            }
            i ++;
        }
        ans.push_back(newInterval);
        return ans;
    }
};