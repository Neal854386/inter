/*
Heapify

Given an integer array, heapify it into a min-heap array.
For a heap array A, A[0] is the root of heap, and for each A[i], A[i * 2 + 1] is the left child of A[i] and A[i * 2 + 2] is the right child of A[i].
Example
Given [3,2,1,4,5], return [1,2,3,4,5] or any legal heap array.
*/


class Solution {
public:
    /**
     * @param A: Given an integer array
     * @return: void
     */
    void heapify(vector<int> &A) {
        // write your code here
        // from the last child to parent
        for (int i = A.size() / 2 - 1; i >= 0; i--) {
            helper(A, i);
        }
    }
    
    void helper(vector<int> &A, int i) {
        int left = get_left(A, i);
        int right = get_right(A, i);
        
        if (left < right && left < A[i]) {
            A[2 * i + 1] = A[i];
            A[i] = left;
            helper(A, 2 * i + 1); 
        } else if (right < A[i]) {
            A[2 * i + 2] = A[i];
            A[i] = right;
            helper(A, 2 * i + 2); 
        }
    }
    
    int get_left(vector<int> &A, int i) {
        return i * 2 + 1 >= A.size() ? INT_MAX : A[2 * i + 1];
    }
    
    int get_right(vector<int> &A, int i) {
        return i * 2 + 2 >= A.size() ? INT_MAX : A[2 * i + 2];
    }
};
