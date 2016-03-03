/*Palindrome Permutation

Difficulty: Easy
Given a string, determine if a permutation of the string could form a palindrome.

For example,
"code" -> False, "aab" -> True, "carerac" -> True.
*/

class Solution {
public:
    bool canPermutePalindrome(string s) {
        int odd = 0, array[256] = {0};
        for (auto c : s) {
            array[c]++;
            odd += array[c] & 1 ? 1 : -1; 
        }
        return odd <= 1;
    }
};