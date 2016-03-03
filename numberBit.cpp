#include <iostream>

using namespace std;

void PrintVertical(int i) {
	int digval = 0;
	int radix = 10;
	while (i != 0) {
	      digval = i % radix;
		  i /= radix;
		  cout << digval << endl;
	}
}


int main(int argc, char *argv[]) {
	PrintVertical(123);
}