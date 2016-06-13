//insert Interval
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
        vector<Interval> res;
        for(int i=0; i<intervals.size(); i++)
        {
            if(newInterval.start>intervals[i].end)
                    res.push_back(intervals[i]);
            else if(newInterval.end<intervals[i].start)
            {
                res.push_back(newInterval);
                res.insert(res.end(), intervals.begin()+i, intervals.end());
                return res;
            }
            else 
            {
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
            }
        }
        res.push_back(newInterval);
        return res;
    }
};


//Merge Intervals
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool comp(Interval a, Interval b)
{
    if(a.start<b.start)
       return true;
    else return false;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
          vector<Interval> res;
          sort(intervals.begin(), intervals.end(), comp);
          for(int i=0; i<intervals.size(); i++)
          {
              if(res.size()==0)
              {
                   res.push_back(intervals[i]);
              }
              else
              {
                  int end = res.size()-1;
                  if( res[end].start <= intervals[i].start && intervals[i].start <= res[end].end)
                         res[end].end = max(res[end].end, intervals[i].end);
                  else   res.push_back(intervals[i]);
              }
          }
          return res;
}
};
