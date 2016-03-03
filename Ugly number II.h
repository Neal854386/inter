// Ugly number II

/*
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number.
*/

#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;


class cmp {
 public:
  bool operator() (const long long a, const long long b) {
      return a > b;
  }
};

class Solution {
public:
    int nthUglyNumber(int n) {
		vector<int> factor_arr = {2,3,5};
        unordered_set<long long> set;
        priority_queue<long long, vector<long long>, cmp> pq;
        long long top = 1;
        pq.push(top);
        set.insert(top);
        while (n - 1 > 0 && !pq.empty()) {
            top = pq.top(); pq.pop();
            long long three = top * 2, five = top * 3, seven = top * 5;
			for (int i = 0; i < factor_arr.size(); i++) {
				long long num = top * factor_arr[i];
				if (!set.count(num)) {
					pq.push(num);
					set.insert(num);
				}
			}
            n--;  
        }
        return pq.top();
    }
};

int main(int argc, char *argv[]) {
	Solution test;
	//for (int i = 1; i < 100; i++) {
		cout << test.nthUglyNumber(1407) << " ";
	//}
}