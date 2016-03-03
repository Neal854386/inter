#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string removeSpaces(string input) {
        // Write your solution here.
        if (input.empty()) {return input;}
        
        int j = 0;
        for (int i = 0; i < input.size(); i++) {
            // to make sure there only one space follow the char
            // because when input[i] == ' ', the input[i - 1] not equal to " "
            if (input[i] != ' ' || (i > 0 && input[i - 1] != ' ')) {
                input[j++] = input[i];
            }
            cout << i << "|" << j << endl;
        }
        if (input[j - 1] == ' ') {
            input.resize(j - 1);
        } else {
            input.resize(j);
        }
        return input;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    auto x = test.removeSpaces("a    a");
    cout << x.size() << endl;
    cout << x << endl;
}