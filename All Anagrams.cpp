#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*
l = "abcbac", s = "ab", return [0, 3] since the substring with 
length 2 starting from index 0/3 are all anagrams of "ab" ("ab", "ba").

*/
class Solution {
 public:
  vector<int> allAnagrams(string l, string s) {
    for (int i : l) {
      map_glob[i]++;
    }
    
    int slow = 0;
    size_t count = 0;
    int s_size = s.size(), l_size = l.size() - 1;
    for (int fast = 0; fast < s_size; fast++) {
        if (fast - slow == l_size) {
            for (int i = slow; i <= fast; i++) {
                  map_sub[s[i]]++;
            }

            for (auto i : map_glob) {
                if (!map_sub.count(i.first) || i.second != map_sub[i.first]) {
                    count = 0;
                    break;
                } else {
                    count++;
                }
            }

            if (count == map_sub.size()) {
                res.push_back(slow);
                count = 0;
            }

            map_sub.clear();
            slow++;
        }  
    }
    return res;
  }
 private:
  unordered_map<char, int> map_glob;
  unordered_map<char, int> map_sub;
  vector<int> res;
};

int main(int argc, char *argv[]) {
	Solution test;
	auto x = test.allAnagrams("a", "aaa");
  for (auto i : x) {
    cout << i << endl;
  }
}