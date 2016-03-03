#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:

    vector<int> kClosest(vector<int> array, int target, int k) {
        if (k == 0) {
          return vector<int> ();
        }
        if (array.empty() || array.size() == 0 || array.size() == 1) {
            return array;
        }
        
        auto index = binary_search(array, target);
        vector<int> res(1, array[index]);
        
        auto mid_ele = array[index];
        int left = 0, right = array.size() - 1, count = 1;
        int l_iter = index - 1, r_iter = index + 1;
        
        while (left <= l_iter && r_iter <= right && count < k) {
            if (mid_ele - array[l_iter] <= array[r_iter] - mid_ele) {
                res.push_back(array[l_iter--]);
            } else {
                res.push_back(array[r_iter++]);
            }
            count++;
        }
        
        // left is over
        if (l_iter > left) {
            while (count < k && r_iter <= right) {
                res.push_back(array[r_iter++]);
                count++;
            }
        }
        
        // right is over
        if (r_iter > right) {
            while (count < k && l_iter >= left) {
                res.push_back(array[l_iter--]);
                count++;
            }
        }
        
        return res;
    }
    
    int binary_search(vector<int> &array, int target) {
        int start = 0, end = array.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (array[mid] == target) {
                return mid;
            } else if (array[mid] < target) {
                start = mid;
            } else if (array[mid] > target) {
                end = mid;
            }
        }
        return abs(array[start] - target) < abs(array[end] - target) ? start : end;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    auto res = test.kClosest({1, 5}, 2, 2);
    for (auto i : res) {
        cout << i << "|";
    }
    
}