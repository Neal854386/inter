/*
211. Add and Search Word - Data structure design
Difficulty: Medium
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . 
means it can represent any one letter.

For example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.
*/

#include <bits/stdc++.h>
using namespace std;

class WordDictionary {
private:
    struct node {
        int end;
        unordered_map<char, node *> ch;
        node():end(0) {}
    } root;

    bool do_search(node *rt, int c, int n, string &word) {
        if (c == n) {
            return rt->end;
        }
        char t = word[c];
        if (t == '.') {
            bool ret = 0;
            for (auto kv : rt->ch) {
                ret |= do_search(kv.second, c + 1, n, word);
                if (ret)
                    return ret;
            }
            return ret;
        } else {
            if (!rt->ch.count(t))
                return 0;
            return do_search(rt->ch[t], c + 1, n, word);
        }
    }
public:
    // Adds a word into the data structure.
    void addWord(string word) {
        node *rt = &root;
        for (char &c : word) {
            if (!rt->ch.count(c))
                rt->ch[c] = new node();
            rt = rt->ch[c];
        }
        rt->end = 1;
    }
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return do_search(&root, 0, word.length(), word);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");