/*
Meeting Rooms II
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), 
find the minimum number of conference rooms required.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return 2.
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
 
class Solution {
public:
    int minMeetingRooms(vector<Interval> &intervals) {
        vector<pair<int, int>> v;
        for (auto &i : intervals) {
            v.push_back(make_pair(i.start, 1));
            v.push_back(make_pair(i.end, 0));
        }
        sort(v.begin(), v.end());
        int ans = 0, tmp = 0;
        for (auto &cur : v) {
            cur.second ? tmp++ : tmp--;
            ans = max(ans, tmp);
        }
        return ans;
    }
};