
/*
208. Implement Trie (Prefix Tree)
Difficulty: Medium
Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.
*/

#include <bits/stdc++.h>

class TrieNode {
public:
    // Initialize your data structure here.
    bool key_exist = false;
    TrieNode* children[26];
    TrieNode(){}    
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        TrieNode* node = root;
        for (int i = 0; i < s.size(); i++) {
            if (!node->children[s[i] - 'a']) {
                node->children[s[i] - 'a'] = new TrieNode();
            }
            node = node->children[s[i] - 'a'];
        }
        node->key_exist = true;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        TrieNode* node = root;
        for (int i = 0; i < key.size(); i++) {
            if(node != nullptr)
                node = node->children[key[i] - 'a'];
            else
                break;
        }

        return node == nullptr ? false : node->key_exist;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (int i = 0; i < prefix.size(); i++) {

            if(node != nullptr)
                node = node->children[prefix[i] - 'a'];
            else
                break;
        }

        return node == nullptr ? false : true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");




#include <bits/stdc++.h>

using namespace std;


class TrieNode {
public:
    // Initialize your data structure here.
    bool key_exist = false;
    TrieNode* children[26] = {nullptr};
    
    TrieNode* findChild(char ch) {
        for (int i = 0; i < 26; i++) {
            if (ch - 'a' == i && children[i] != nullptr) {
                return children[i];
            }
        }
        return nullptr;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        TrieNode* node = root;
        for (auto ch : s) {
            if (node->children[ch - 'a'] == nullptr) {
                node->children[ch - 'a'] = new TrieNode();
            }
            node = node->children[ch - 'a'];
        }
        node->key_exist = true;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    // Using DFS to find every words
    vector<string> startsWith(string prefix) {
        vector<string> res;
        string str = prefix;
        TrieNode* node = root;
        for (auto ch : prefix) {
            if (node->children[ch - 'a']) {
                node = node->children[ch - 'a'];
            }
        }
        
        helper(str, res, node);
        return res;
    }

    void helper(string &prefix, vector<string> &res, TrieNode* curr) {
        if (!curr) {return;}
        if (curr->key_exist) {res.push_back(prefix);}
        for (int i = 0; i < 26; i++) {
            prefix.push_back('a' + i);
            helper(prefix, res, curr->children[i]);
            prefix.pop_back();
        }
        return;
    }

    TrieNode* root;
};

int main(int argc, char *argv[]) {
    Trie test;
    test.insert("someboday");
    test.insert("something");
    test.insert("some");
    test.insert("someword");
    test.insert("Hello");
    auto res = test.startsWith("some");
    for (auto str : res) cout << str << endl;
}