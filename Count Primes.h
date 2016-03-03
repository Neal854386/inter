// Count Primes 

/*
Description:

Count the number of prime numbers less than a non-negative number, n.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
		int count = 0;
        bool prime[n];
        prime[0] = false, prime[1] = false;
        for (int i = 2; i < n; i++) {prime[i] = true;}
        for (int i = 0; i < sqrt(n); ++i) {
            if (prime[i]) {
                for (int j = i * i; j < n; j += i) {
                    prime[j] = false;
                }    
            }    
        }
        
		for (int i = 0; i < n; i++) {
			if (prime[i]) {count++;}
		}
		return count;
    }
};

int main(int argc, char *argv[]) {
	Solution test;
	cout << test.countPrimes(1004);
}