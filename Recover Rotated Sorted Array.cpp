class Solution {
private:
    void swap(vector<int> &num, int i, int j) {
        if (i != j) {
            int tmp = num[i];
            num[i]= num[j];
            num[j] = tmp;            
        }
    }
    void reverse(vector<int> &num, int i, int j) {
        while(i < j) {
           swap(num, i++, j--);        
        }
    }
    // find Shift Position 
    int findMinPoint(vector<int> &A) {
       int start = 0, end = A.size() - 1;
       if (A[start] < A[end]) return start;
       
       while(start + 1 < end && A[start] > A[end]) {
           int mid = start + (end - start) / 2;
           if (A[mid] < A[end]) { 
              end = mid;
           }
           else { 
              start = mid;
           }
       }
       return end;
    }

public:
    void recoverRotatedSortedArray(vector<int> &nums) {
        int mid = findMinPoint(nums);
        if (mid == 0) return;
        reverse(nums, 0, mid - 1);
        reverse(nums, mid, nums.size() - 1);
        reverse(nums, 0, nums.size() - 1);
    }
};