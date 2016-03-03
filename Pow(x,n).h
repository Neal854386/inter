/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 6, 2013
 Update:     Jul 15, 2013
 Problem:    Pow(x, n)
 Difficulty: easy
 Source:     http://leetcode.com/onlinejudge#question_50
 Notes:
 Implement pow(x, n).
 
 Solution: recursion.
 */

class Solution {
public:
    double pow(double x, int n) {
        if (x < 0) return (n % 2 == 0) ? pow(-x, n) : -pow(-x, n);
        if (x == 0 || x == 1) return x;
        if (n < 0) return 1.0 / pow(x, -n);
        if (n == 0) return 1.0;
        
        double half = pow(x, n / 2);
        if (n % 2 == 0) return half * half;
        else return x * half * half;
    }
};

class Solution {
public:
    double myPow(double x, int n) {
        long long N = (long long) n;
        if (N < 0) {N = -N;}
        
        double ret = 1.0;
        double X = (double) x;
        
        while (N) {
            if (N & 1LL) // is odd number
                ret *= X, N--;
            else
                X *= X, N /= 2;
        }
        return n < 0 ? 1 / ret : ret;        
    }
};

int main() {
    vector<pair<int, int>> input = {
        {2, INT_MAX},
        {3, 4},
        {5, 6},
        {7, 8},
        {9, 0}
    };
    for (auto &ip : input)
        printf("%f,%f\n", pow(ip.first, ip.second), pow(ip.second, ip.first));
}
