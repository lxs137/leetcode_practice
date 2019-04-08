struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> newIntervals;
        if (intervals.size() == 0) {
            return newIntervals;
        } else if (intervals.size() == 1) {
            newIntervals.emplace_back(intervals[0].start, intervals[0].end);
            return newIntervals;
        }
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){
            return a.start < b.start;
        });
        Interval &curInterval = intervals[0];
        for (auto &interval : intervals) {
            if (curInterval.end >= interval.start) {
                curInterval.end = max(interval.end, curInterval.end);
            } else {
                newIntervals.emplace_back(curInterval.start, curInterval.end);
                curInterval = interval;
            }
        }
        newIntervals.emplace_back(curInterval.start, curInterval.end);
        return newIntervals;
    }
};