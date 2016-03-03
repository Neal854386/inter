/*
 print all palindromes substrings in a string
 */

#include <bits/stdc++.h>

using namespace std;

void printPalindromes(string& str) { 
    int N = str.length();
    bool dp[N][N];
  
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        dp[i][j] = false;
      }
    }
  
    for (int i = 0; i < N; i++) {
          dp[i][i] = true;
    }
  
  
    for (int j = 0; j < N; j++) {
      for (int i = 0; i < j; i++) {
         dp[i][j] = (str[i] == str[j]) && (dp[i + 1][j - 1] || j - i < 2);
      }
    }
  
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (dp[i][j]) {
          cout << str.substr(i, j - i + 1) << endl;
        }
      }
    }
}

int main() {
  string str = "aab";
  printPalindromes(str);
}