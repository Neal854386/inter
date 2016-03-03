/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 8, 2013
 Problem:    Search for a Range
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_34
 Notes:
 Given a sorted array of integers, find the starting and ending position of a given target value.

 Your algorithm's runtime complexity must be in the order of O(log n).

 If the target is not found in the array, return [-1, -1].

 For example,
 Given [5, 7, 7, 8, 8, 10] and target value 8,
 return [3, 4].

 Solution: It takes O(lgN) to find both the lower-bound and upper-bound.
 */

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res(2, -1);
        int lower = getLowerBound(A, n, target);
        int upper = getUpperBound(A, n, target);
        if (lower <= upper) {
            res[0] = lower;
            res[1] = upper;
        }
        return res;
    }
    
    int getLowerBound(int A[], int n, int target)
    {
        int l = 0, u = n-1;
        while (l <= u)
        {
            int mid = (l + u) / 2;
            if (A[mid] < target)
                l = mid + 1;
            else
                u = mid - 1;
        }
        return l;
    }
    
    int getUpperBound(int A[], int n, int target)
    {
        int l = 0, u = n-1;
        while (l <= u)
        {
            int mid = (l + u) / 2;
            if (A[mid] <= target)
                l = mid + 1;
            else
                u = mid - 1;
        }
        return u;
    }
};


class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int lower = get_lower(A, n, target);
        int upper = get_upper(A, n, target);
        res.push_back(lower);
        res.push_back(upper);
        return res;
    }
    
    int get_lower(int A[], int n, int target) {
        int start = 0, end = n - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (A[mid] >= target) {
                end = mid;
            } else if (A[mid] < target) {
                start = mid;
            }
        }
        
        if (A[start] == target) {
            return start;
        } else if (A[end] == target) {
            return end;
        }
        return -1;
    }

    
    
    int get_upper(int A[], int n, int target) {
        int start = 0, end = n - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (A[mid] > target) {
                end = mid;
            } else if (A[mid] <= target) {
                start = mid;
            }
        }
        
        if (A[end] == target) {
            return end;
        } else if (A[start] == target) {
            return start;
        }
        return -1;
    }

private:
    vector<int> res;
};