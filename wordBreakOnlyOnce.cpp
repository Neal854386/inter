#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
   void wordBreakOnlyOnce(string str, unordered_set<string> &dict) {
		if (str.empty()) {return;}
		const int n = str.size();
		// i means length
		for (int i = 1; i < n; i++) {
			if (dict.count(str.substr(0, i)) && dict.count(str.substr(i, n - i)) ) {
				cout << str.substr(0, i) << endl;
				cout << str.substr(i, n - i) << endl;
			}
		}
    }
};

int main(int argc, char *argv[]) {
	string input = "leetcode";
	unordered_set<string> dict;
	dict.insert("leet");
	dict.insert("code");
	Solution test;
	test.wordBreakOnlyOnce(input, dict);
}