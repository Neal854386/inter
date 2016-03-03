#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> solve(vector<int> array, int target) {
        // write your code here
        vector<int> res(2, 0);
        if (array.size() < 2) {return res;}
        sort(array.begin(), array.end());
        long res_sum = INT_MAX; // inorder to avoid overflow

        for (int begin = 0, end = array.size() - 1; begin < end;) {
            int cur_sum = array[begin] + array[end];
            
            if(abs(cur_sum - target) < abs(res_sum - target)) {
                res_sum = cur_sum;
                res[0] = array[begin]; res[1] = array[end];
            }
            
            if(cur_sum < target) {
                begin++;
            } else if(cur_sum > target) {
                end--;
            } else {
                res[0] = array[begin]; res[1] = array[end];
                return res;
            }
        }
        
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
	auto res = test.solve({1, 4, 7, 13}, 7);
	cout << res[0] << " "<< res[1] << endl;
}