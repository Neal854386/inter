/*

Sort Colors II Show Result My Submissions

Given an array of n objects with k different colors (numbered from 1 to k), sort them so that objects of the same color are adjacent, with the colors in the order 1, 2, ... k.

Note
You are not suppose to use the library's sort function for this problem.

Example
GIven colors=[3, 2, 2, 1, 4], k=4, your code should sort colors in-place to [1, 2, 2, 3, 4]. 

Challenge
A rather straight forward solution is a two-pass algorithm using counting sort. That will cost O(k) extra memory.

Can you do it without using extra memory?

*/
class Solution{
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */    
    void sortColors2(vector<int> &colors, int k) {
        int count = 0, start = 0, end = colors.size() - 1;
        while (count < k) {
            int cur_min = INT_MAX, cur_max = INT_MIN;
            
            for (int i = start; i < end; i++) {
                cur_min = min(cur_min, colors[i]); cur_max = max(cur_max, colors[i]);
            }

            int left = start, right = end, cur = left;
            
            while(cur <= right) {
                if (colors[cur] == cur_min) {
                    swap(colors[left++], colors[cur++]);
                } else if (cur_min < colors[cur] && colors[cur] < cur_max) {
                    cur++;
                } else if (colors[cur] == cur_max){
                    swap(colors[cur], colors[right--]);
                }
            }
            count += 2; start = left; end = right;
        }
    }
};


class Solution{
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */    
    void sortColors2(vector<int> &colors, int k) {
        int target = 0, start = 0, end = colors.size() - 1;
        while (target < k) {
           partition(colors, start, end, target);
           target++;
        }
        return;
    }
    
    // The start in change in every time of partition, but the end will not change
    void partition(vector<int> &a, int &start, int end, int &target) {
        while (start <= end) {
            while (start <= end && a[start] == target) {
                start++;
            }
            while (start <= end && a[end] != target) {
                end--;
            }            
            if (start <= end) {
                swap(a[start++], a[end--]);
            }
        }
        return;
    }
};

