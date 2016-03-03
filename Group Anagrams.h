/*
Group Anagrams
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:
For the return value, each inner list's elements must follow the lexicographic order.
All inputs will be in lower-case.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
      vector<vector<string>> v;
      if(!strs.size()) return v;
      unordered_map<string, int> m;
      for (string &s : strs) {
          string tmp(s);
          sort(tmp.begin(), tmp.end());
          if (m.count(tmp)) {
              v[m[tmp]].push_back(s);
              sort(v[m[tmp]].begin(), v[m[tmp]].end());
          } else {
              v.push_back(vector<string>({s}));
              m[tmp] = v.size() - 1;
          }
      }
      return v;
  }
};