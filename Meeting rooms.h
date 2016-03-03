/*
Meeting Rooms My Submissions Question
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), 
determine if a person could attend all meetings.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return false.
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


bool comp(const Interval &a, const Interval &b) {
        return a.start < b.start;
}
 
class Solution {
public:
    bool canAttendMeetings(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int e = INT_MIN;
        for (auto &i : intervals) {
            if (i.start < e) return false;
            e = max(e, i.end);
        }
        return true;
    }
};

bool compare(Interval a, Interval b) {
        if (a.end != b.end)
            return a.end < b.end;
        else 
            return a.start > b.start;
}
class Solution {
public:

    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.empty()) return true;
        sort(intervals.begin(), intervals.end(), compare);
        Interval pre = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (pre.end > intervals[i].start) {
                return false;
            }
            pre = intervals[i];
        }
        return true;
    }
};