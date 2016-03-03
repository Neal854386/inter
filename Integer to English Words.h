/*
273. Integer to English Words
Difficulty: Medium
Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

For example,
123 -> "One Hundred Twenty Three"
12345 -> "Twelve Thousand Three Hundred Forty Five"
1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
*/

class Solution {
private:
    string B[8] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string C[19] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    
    string convert(int n) {
        if (n >= 1000000000) {
            return convert(n / 1000000000) + " Billion" + convert(n % 1000000000);
        } else if (n >= 1000000) {
            return convert(n / 1000000) + " Million" + convert(n % 1000000);
        } else if (n >= 1000) {
            return convert(n / 1000) + " Thousand" + convert(n % 1000);
        } else if (n >= 100) {
            return convert(n / 100) + " Hundred" + convert(n % 100);
        } else if (n >= 20) {
            return " " + B[n / 10 - 2] + convert(n % 10);
        } else if (n >= 1) {
            return " " + C[n - 1];
        }
        return "";
    }
public:
    string numberToWords(int num) {
        if (!num)
            return "Zero";
        return convert(num).substr(1);
    }
};