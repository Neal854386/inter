/*
Group Shifted Strings
Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:

"abc" -> "bcd" -> ... -> "xyz"
Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.

For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"], 
Return:

[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]
*/

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> map;
        for (string &s : strings) {
            string k = s;
            // the k in here is the base for every words
            for (int i = 0; i < k.length(); i++) {
                k[i] = k[i] >= s[0] ? k[i] - s[0] + 'a' : k[i] - s[0] + 'a' + 26;
            }
            map[k].push_back(s);
        }
        
        vector<vector<string>> ans;
        for (auto &p : map) {
            sort(p.second.begin(), p.second.end());
            ans.push_back(p.second);
        }
        return ans;
    }
};