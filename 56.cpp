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
    static bool cmp(Interval a, Interval b)
    {
        if(a.start < b.start)
            return true;
        else if(a.start > b.start)
            return false;
        else
            return a.end < b.end;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ans;
        if(intervals.empty())
            return ans;
        sort(intervals.begin(), intervals.end(), cmp);
        ans.push_back(intervals[0]);
        for(int i = 1;i < intervals.size();i++)
        {
            if(intervals[i].end <= ans.back().end)
            {
                continue;
            }
            else
            {
                if(intervals[i].start > ans.back().end)
                {
                    ans.push_back(intervals[i]);
                }
                else
                {
                    ans.back().end = intervals[i].end;
                }
            }
        }
        return ans;
    }
};