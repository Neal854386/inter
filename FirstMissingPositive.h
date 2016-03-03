/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 21, 2013
 Problem:    First Missing Positive
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_41
 Notes:
 Given an unsorted integer array, find the first missing positive integer.
 For example,
 Given [1,2,0] return 3,
 and [3,4,-1,1] return 2.
 Your algorithm should run in O(n) time and uses constant space.

 Solution: Although we can only use constant space, we can still exchange elements within input A!
           Swap elements in A and try to make all the elements in A satisfy: A[i] == i + 1.
           Pick out the first one that does not satisfy A[i] == i + 1.
 */

/*
试图让A[i]这个值x的index是x – 1，
即每个index身上的元素都是index本身+1。所以{1 2 3}就是理想中的新数组，{1 5 3}就说明缺2。

如果A[i]不在自己该在的地方，就想办法把他换到该在的地方。
如果A[i]是<=0或者A[i]比数组长度还大，说明没有它该在的地方，那就skip他，弄下一个（不用担心当前位置被它占了，如果后面有想在这个位置的正整数，它会被换走的）
A[i]和A[A[i] – 1]换，然后继续回到i，接着换，直到第一种情况满足。但是如果这俩数一样，换也没用，就别原地打转了。
*/

class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n;) {
            if (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            } else {
                i++;
            }
        }
  
        for (int i = 0; i < n; i++) {
            if (nums[i] != (i + 1)) {
                return i + 1;
            }
        }
        return n + 1;
    }
};