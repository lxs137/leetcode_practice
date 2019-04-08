struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> out;
        if (intervals.size() == 0) {
            out.emplace_back(newInterval.start, newInterval.end);
            return out;
        }
        int i = 0, n = intervals.size();
        for (; i < n; i++) {
            if (intervals[i].start >= newInterval.start)
                break;
        }
        if (i == 0) {
            intervals.insert(intervals.begin(), newInterval);
        } else {
            intervals.insert(intervals.begin() + i, newInterval);
        }
        out = merge(intervals);
        return out;
    }

    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> newIntervals;
        if (intervals.size() == 0) {
            return newIntervals;
        } else if (intervals.size() == 1) {
            newIntervals.emplace_back(intervals[0].start, intervals[0].end);
            return newIntervals;
        }
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