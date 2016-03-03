#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  string longestCommon(string s, string t) {
    const int s_len = s.size(), t_len = t.size();
    string res;
    if (s_len == 0 || t_len == 0) {return res;}
    
    int dp[s_len + 1][t_len + 1];
    memset(dp, 0, sizeof(dp));
    int res_len = 0, end_pos = 0;
    
    for (int i = 1; i <= s_len; i++) {
      for (int j = 1; j <= t_len; j++) {
        if (s[i - 1] == t[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
          if (dp[i][j] > res_len) {
            res_len = dp[i][j];
            end_pos = i;
          }
        }
      }
    }
    return s.substr(end_pos - res_len, res_len);
  }
};

int main(int argc, char *argv[]) {
	Solution test;
	cout << test.longestCommon("abcde", "cdf");
}