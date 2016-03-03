/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 13, 2013
 Update:     Aug 24, 2013
 Problem:    Spiral Matrix II
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_59
 Notes:
 Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
 For example,
 Given n = 3,
 You should return the following matrix:
 [
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
 ]

 Solution: ...
 */

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        if (n == 0) return vector<vector<int> >();
        vector<vector<int> > res(n, vector<int>(n));
        int imin = 0, imax = n-1, jmin = 0, jmax = n-1;
        int number = 1;
        while (true)
        {
            for (int j = jmin; j <= jmax; ++j) res[imin][j] = number++;
            if (++imin > imax) break;
            for (int i = imin; i <= imax; ++i) res[i][jmax] = number++;
            if (jmin > --jmax) break;
            for (int j = jmax; j >= jmin; --j) res[imax][j] = number++;
            if (imin > --imax) break;
            for (int i = imax; i >= imin; --i) res[i][jmin] = number++;
            if (++jmin > jmax) break;
        }
        return res;
    }
};

class Solution {
public:
  vector<vector<int> > solve(int n) {
    if (n == 0) return vector<vector<int> >();
    vector<vector<int> > res(n, vector<int>(n));
    int row_min = 0, row_max = n - 1, col_min = 0, col_max = n - 1;
    int num = 1;
    while (true) {
        for (int col = col_min; col <= col_max; col++) {res[row_min][col] = num++;}
        if (++row_min > row_max) {break;}
        for (int row = row_min; row <= row_max; row++) {res[row][col_max] = num++;}
        if (col_min > --col_max) {break;}
        for (int col = col_max; col >= col_min; col--) {res[row_max][col] = num++;}
        if (row_min > --row_max) {break;}
        for (int row = row_max; row >= row_min; row--) {res[row][col_min] = num++;}
        if (++col_min > col_max) {break;}
    }
    return res;
  }  
};

class Solution {
public:
  vector<vector<int> > solve(int row_num, int col_num) {
    vector<vector<int> > res(row_num, vector<int>(col_num));
    int row_min = 0, row_max = row_num - 1, col_min = 0, col_max = col_num - 1;
    int num = 1;
    while (true) {
        for (int col = col_min; col <= col_max; col++) {res[row_min][col] = num++;}
        if (++row_min > row_max) {break;}
        for (int row = row_min; row <= row_max; row++) {res[row][col_max] = num++;}
        if (col_min > --col_max) {break;}
        for (int col = col_max; col >= col_min; col--) {res[row_max][col] = num++;}
        if (row_min > --row_max) {break;}
        for (int row = row_max; row >= row_min; row--) {res[row][col_min] = num++;}
        if (++col_min > col_max) {break;}
    }
    return res;
  }  
};

