#include <iostream>
#include <vector>
using namespace std;

 
void reverse(string &A, int start, int end) {
        while(start < end) {
            char t = A[start];
            A[start++] = A[end];
            A[end--] = t;
        }
}

    string rotateString(string A, int offset) {
        if (A.length() < 2) return A;
       
        int len = offset % A.size();
        reverse(A, 0, A.size() - len - 1);
        reverse(A, A.size() - len, A.size() - 1);
        reverse(A, 0, A.size() - 1);
        return A;
    }
   

int main(int argc, char *argv[]) {
 
	rotateString("abcdefg", 2);
}