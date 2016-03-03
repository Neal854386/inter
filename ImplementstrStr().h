/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 9, 2013
 Update:     Jul 19, 2013 (Refactor)
 Problem:    Implement strStr()
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_28
 Notes:
 Implement strStr().
 Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.

 Solution: Check in the haystack one by one. If not equal to needle, reset the pointer.
 */

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        while(true) {
            char *h = haystack, *n = needle;
            while (*n != '\0' && *h == *n) {
                h++; n++;
            }
            if (*n == '\0') return haystack;
            if (*h == '\0') return NULL;
            haystack++;
        }
    }
};


class Solution {
public:
    int strStr(char *source, char *target) {
        if (source == NULL || target == NULL) {
            return -1;
        }
        int len1 = strlen(source), len2 = strlen(target);
        
        for (int i = 0; i <= len1 - len2; i++) {
            int j = 0;
            for (; j < len2; j++) {
                if (source[i + j] != target[j]) {
                    break;
                }
            }

            if (j == len2) {
                return i;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int strStr(string source, string target) {
        int len1 = source.size(), len2 = target.size();
        
        if (len2 > len1) {
            return -1;
        }
        
        if (source.empty() || target.empty()) {
            return 0;
        }
        
        for (int i = 0; i <= len1 - len2; i++) {
            int j = 0;
            for (; j < len2; j++) {
                if (source[i + j] != target[j]) {
                    break;
                }
            }

            if (j == len2) {
                return i;
            }
        }
        return -1;
    }
};

// RK 算法