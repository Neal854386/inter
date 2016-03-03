#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int longest(string s, string t) {
        // write your solution here
        int res = 0;
        int s_len = s.size(), t_len = t.size();
        if (s_len == 0 || t_len == 0) return res;
        
        int dp[s_len + 1][t_len + 1];
        memset(dp, 0, sizeof(dp));
        
        for (int i = 1; i <= s_len; i++) {
            for (int j = 1; j <= t_len; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    res = max(res, dp[i][j]);
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
	cout << test.longest("abcde","cbabdfe");
}