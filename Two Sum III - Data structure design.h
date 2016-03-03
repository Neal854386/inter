/*
Two Sum III - Data structure design

Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

For example,
add(1); add(3); add(5);
find(4) -> true
find(7) -> false
*/


class TwoSum {
private:
    unordered_map<int, int> ht;
public:
    // Add the number to an internal data structure.
	void add(int number) {
	    ht[number]++;
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
	    for (auto &p : ht) {
	        if (ht.count(value - p.first))
	            if (value - p.first != p.first)
	                return true;
	            else if (p.second > 1)
	                return true;
	    }
	    return false;
	}
};
