class Solution {
public:
    /**
     * @param s : A string
     * @return : A string
     */
    string reverseWords(string s) {
        // write your code here
        string rev;
        int begin = -1;
    
        for(int i = s.size() - 1;; i--) {
            if(i < 0 || s[i] == ' ') {
                if(begin == -1 && i >= 0) {
                    continue;
                }
                else {
                    rev += s.substr(i + 1, begin - i);
                    rev += " ";
                    begin = -1;
                }
                if(i < 0) {
                    break;
                }
            } else {
                if(begin == -1) { begin = i;}
            }
        }
        while(!rev.empty() && rev.back() == ' ') {rev.pop_back();}
        return rev;
    }
};

class Solution {
public:
    /**
     * @param s : A string
     * @return : A string
     */
    string reverseWords(string s) {
        // write your code here
        string rev;
        int j = s.size();
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                j = i;
            } else if (i == 0 || s[i - 1] == ' ') {
                if (rev.size() != 0) {
                    rev += ' ';
                }
                // in C++ the second parameter in substr is len, not the end pos for substring
                rev += s.substr(i, j - i);
            }
        }
        while(!rev.empty() && rev.back() == ' ') rev.pop_back();
        return rev;
    }
};


class Solution
{
public:
    void swap(char* str, int i, int j){
        char t = str[i];
        str[i] = str[j];
        str[j] = t;
    }

    void reverse_string(char* str, int length){
        for(int i = 0; i < length / 2; i++){
            swap(str, i, length - i - 1);
        }
    }
    void reverse_words(char* str){
        int l = strlen(str);
        //Reverse string
        reverse_string(str, strlen(str));
        int p = 0;
        
        //Find word boundaries and reverse word by word
        for(int i = 0; i < l; i++){
            if(str[i] == ' '){
                reverse_string(&str[p], i - p);
                p = i + 1;
            }
        }
        //Finally reverse the last word.
        reverse_string(&str[p], l - p);
    }
    
};
