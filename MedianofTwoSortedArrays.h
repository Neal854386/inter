/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Jul 10, 2013
 Problem:    Median of Two Sorted Arrays
 Difficulty: Hard
 Source:     http://leetcode.com/onlinejudge#question_4
 Notes:
 There are two sorted arrays A and B of size m and n respectively. 
 Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

 Solution: 1. O(m+n)
           2. O(log(m+n))
           3. O(logm + logn)
*/


class Solution {
public:
    double median(vector<int> num1, vector<int> num2) {
        int *A = &num1[0];
        int *B = &num2[0];
        sort(num1.begin(), num1.end());
        sort(num2.begin(), num2.end());      
        int m = num1.size(), n = num2.size();
        int total = m + n;
        if (total & 0x1)
            return findKth(A, m, B, n, total / 2 + 1);
        else
            return (findKth(A, m, B, n, total / 2) + findKth(A, m, B, n, total / 2 + 1)) / 2;
    }
    
    
    double findKth(int*A, int size_a, int *B, int size_b, int k) {
        if (size_a > size_b) {
            return findKth(B, size_b, A, size_a, k);
        } else if (!size_a || !size_b) {
            return !size_a ? B[k - 1] : A[k - 1];
        } else if (k == 1) {
            return min(A[0], B[0]);
        }
        
        int a = min(size_a, k / 2); // get one half for the array
        int b = k - a;           // get the other half
        // now the all array will be divde by those two index a and b
        // base case for end
        
        if (A[a - 1] == B[b - 1]) {
            return A[a - 1];
        } else {
            // if B[b - 1] we choose array B, so we increse the index of start array A
            return  A[a - 1] < B[b - 1] ?
            findKth(A + a, size_a - a, B, size_b, k - a):
            findKth(A, size_a, B + b, size_b - b, k - b);
        }
    }
};

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        return findMedianSortedArrays_1(A, m, B, n);
    }

    double findMedianSortedArrays_1(int A[], int m, int B[], int n) {
        int i = 0, j = 0;
        int m1 = 0, m2 = 0;
        int total = m + n;

        for (int k = 0; k <= total / 2; ++k)
        {
            int a = (i == m) ? INT_MAX : A[i];
            int b = (j == n) ? INT_MAX : B[j];

            m1 = m2;
            m2 = min(a, b);

            if (a < b) i++;
            else j++;
        }

        if (total & 0x1) return m2;
        else return (m1 + m2) / 2.0;
    }

    double findMedianSortedArrays_2(int A[], int m, int B[], int n) {
        int total = m + n;
        if (total & 0x1)
            return findKthSortedArrays(A, m, B, n, total / 2 + 1);
        else
            return (findKthSortedArrays(A, m, B, n, total / 2) + findKthSortedArrays(A, m, B, n, total / 2 + 1)) / 2;
    }

    double findKthSortedArrays(int A[], int m, int B[], int n, int k) {
        if (m > n)
            return findKthSortedArrays(B, n, A, m, k);
        if (m == 0) return B[k-1];
        if (k == 1) return min(A[0], B[0]);

        int i = min(k / 2, m);
        int j = k - i;
        int a = A[i-1];
        int b = B[j-1];

        if (a < b) return findKthSortedArrays(A + i, m - i, B, n, k - i);
        else if (a > b) return findKthSortedArrays(A, m, B + j, n - j, k - j);
        else return a;
    }

    double findMedianSortedArrays_3(int A[], int m, int B[], int n) {
        return findMedian(A, m, B, n, max(0, (m + n) / 2 - n), min(m - 1, (m + n) / 2));
    }

    double findMedian(int A[], int m, int B[], int n, int l, int r) {
        if (l > r)
            return findMedian(B, n, A, m, max(0, (m + n) / 2 - m), min(n, (m + n) / 2));

        int i = (l + r) / 2;
        int j = (m + n) / 2 - i;

        int Ai_1 = (i == 0) ? INT_MIN : A[i-1];
        int Bj_1 = (j == 0) ? INT_MIN : B[j-1];
        int Ai = (i == m) ? INT_MAX : A[i];
        int Bj = (j == n) ? INT_MAX : B[j];

        if (Ai < Bj_1) return findMedian(A, m, B, n, i+1, r);
        if (Ai > Bj) return findMedian(A, m, B, n, l, i-1);

        if ((m + n) % 2 == 1) return Ai;
        else return (Ai + max(Ai_1, Bj_1)) / 2.0;
    }
};


class Solution {

    doubld findKthSmall(vector<int> &a, int a_left, vecotor<int> &b, int b_left, int k) {
        if (k == 1) {
            return min(a[a_left], b[b_left]);
        }

        if (a_left >= a.size()) {return b[b_left + k - 1];}
        if (b_left >= b.size()) {return a[a_left + k - 1];}

        int a_half_kth = a_left + k / 2 - 1 < a.size() ? a[a_left + k / 2 - 1] : INT_MAX;
        int b_half_kth = b_left + k / 2 - 1 < b.size() ? b[b_left + k / 2 - 1] : INT_MAX;

        if (a_half_kth < b_half_kth) {
            return findKthSmall(a, a_left + k / 2, b, b_left, k - k / 2);
        } else {
            return findKthSmall(a, a_left, b, b_left + k / 2, k - k / 2);
        }
    }
};

