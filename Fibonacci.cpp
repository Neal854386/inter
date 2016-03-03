#include <iostream>

using namespace std;

int Fibonacci_loop(int n) {
	int cur = 0, f0 = 0, f1 = 1;
	for (int i = 1; i < n; i++) {
		cur = f0 + f1;
		f0 = f1;
		f1 = cur;
	}
	return cur;
}

int Fibonacci_tail(int n, int acc1, int acc2) {
	if (n == 0) {
		return 0;
	}
	
	if (n < 2) {
		return acc1;
	}
	return Fibonacci_tail(n - 1, acc2, acc1 + acc2);
}

int Fibonacci(int n) {
	if (n == 0) {
		return 0;
	}
	
	if (n <= 2) {
		return 1;
	}

	return Fibonacci(n - 1) + Fibonacci(n - 2);
}
int main(int argc, char *argv[]) {
	cout << Fibonacci(20) << endl;;
	cout << Fibonacci_tail(20, 1, 1) << endl;
	cout << Fibonacci_loop(20) << endl;
}