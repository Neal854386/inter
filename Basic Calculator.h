/*
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
Note: Do not use the eval built-in library function.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool is_operator(char &c) {
        return c == '(' || c == ')' || c == '+' || c == '-' ||
               c == '*' || c == '/';
    }
    void calc(stack<char> &ops,stack<long long> &suf) {
        char op = ops.top();
        ops.pop();
        long long op1 = suf.top();
        suf.pop();
        long long op2 = suf.top();
        suf.pop();
        long long ans = 0;
        switch (op) {
            case '+': ans = op2 + op1; break;
            case '-': ans = op2 - op1; break;
            case '*': ans = op2 * op1; break;
            case '/': ans = op2 / op1; break;
            default:  break;
        }
        suf.push(ans);
    }
public:
    int calculate(string s) {
        stack<char> ops;
        stack<long long> suf;
        unordered_map<char,int> pred({
            {'*', 2}, {'/', 2}, {'+', 1}, {'-', 1}
        });
        int n=s.length(), l = 0;
        while (l < n) {
            while (l < n && s[l] == ' ')
                l++;
            if (l == n)
                break;
            int r = l;
            while (r < n && !is_operator(s[r]))
                r++;
            if (r == l) { // operator
                if (s[r] == '(') {
                    ops.push(s[r]);
                } else if (s[r] == ')') {
                    while (ops.top() != '(')
                        calc(ops, suf);
                    ops.pop();
                } else {
                    while (!ops.empty() && pred[ops.top()] >= pred[s[r]])
                        calc(ops,suf);
                    ops.push(s[r]);
                }
            } else {    // operand
                suf.push(stoll(s.substr(l, r - l), 0, 10));
            }
            l = r == l ? r + 1 : r;
        }
        while (!ops.empty())
            calc(ops,suf);
        return suf.top();
    }
};