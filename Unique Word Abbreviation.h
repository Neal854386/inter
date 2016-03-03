/*
288. Unique Word Abbreviation

An abbreviation of a word follows the form <first letter><number><last letter>. Below are some examples of word abbreviations:

a) it                      --> it    (no abbreviation)

     1
b) d|o|g                   --> d1g

              1    1  1
     1---5----0----5--8
c) i|nternationalizatio|n  --> i18n

              1
     1---5----0
d) l|ocalizatio|n          --> l10n
Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary. 
A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.

Example: 
Given dictionary = [ "deer", "door", "cake", "card" ]

isUnique("dear") -> false
isUnique("cart") -> true
isUnique("cane") -> false
isUnique("make") -> true
*/

/*
map<string, set<string>>
time(N * L)
*/

class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> dictionary) {
        for(auto word : dictionary){
            auto abbr = getAbbr(word);
            mp[abbr].insert(word);
        }
    }

    bool isUnique(string word) {
        string abbr = getAbbr(word);
        // if doesn't has abbr,
        // or has only one word in this abbr
        if (!mp.count(abbr) || (mp[abbr].count(word) && mp[abbr].size() == 1)) {
            return true;
        }
        return false;
    }
    
    string getAbbr(string str) {
        int n = str.length();
        if (n < 3) {
            return str;
        }
        return str[0] + to_string(n - 2) + str[n - 1];
    }
    
private:
    unordered_map<string, unordered_set<string>> mp;
};




