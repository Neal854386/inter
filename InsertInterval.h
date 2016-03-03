/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Jun 7, 2013
 Problem:    Insert Interval
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_57
 Notes:
 Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 You may assume that the intervals were initially sorted according to their start times.
 Example 1:
 Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 Example 2:
 Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
 This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

 Solution: For example 2:
           1. compare [1,2] with [4,9], then insert [1,2];
           2. merge [3,5] with [4,9], get newInterval = [3,9];
           3. merge [6,7] with [3,9], get newInterval = [3,9];
           4. merge [8,10] with [3,9], get newInterval = [3,10];
           5. compare [12,16] with [3,10], insert newInterval [3,10], then all the remaining intervals...
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
    vector<Interval> insert(vector<Interval> &intervals, const Interval newInterval) {
        vector<Interval> res;
        int insert_idx = 0;

        for (auto interval : intervals) {
            if (interval.end < newInterval.start) {
                res.push_back(interval);
                insert_idx++;
            } else if (interval.start > newInterval.end) {
                res.push_back(interval);
            } else {
                newInterval.start = min(interval.start, newInterval.start);
                newInterval.end = max(interval.end, newInterval.end);
            }
        }
        res.insert(res.begin() + insert_idx, newInterval);
        return res;
    }
};