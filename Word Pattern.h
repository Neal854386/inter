/*
Word Pattern
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
*/

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> dict;
        unordered_set<string> used;
        stringstream ss(str);
        istream_iterator<std::string> begin(ss);
        istream_iterator<std::string> end;
        vector<string> tokens(begin, end);
        if(tokens.size() != pattern.length())
            return false;
            
        for (int i = 0; i < pattern.length(); i++) {
            if (!dict.count(pattern[i])) {
                if(!used.count(tokens[i])) {
                    dict[pattern[i]] = tokens[i];
                    used.insert(tokens[i]);
                } else {
                    return false;
                }
            } else if(dict[pattern[i]] != tokens[i])
                return false;
        }
        return true;
    }
};