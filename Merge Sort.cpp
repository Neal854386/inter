#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> mergeSort(vector<int> array) {
        // Write your solution here
        int start = 0, end = array.size() - 1;
        return merge_sort(array, start, end);
    }
    
    vector<int> merge_sort(vector<int> array, int start, int end) {
        if (start == end) {
            return vector<int> (1, array[start]);
        } else if (start < end) {
            auto mid = start + (end - start) / 2;
            return merge(merge_sort(array, start, mid), merge_sort(array, mid + 1, end));
        } else if (start > end) {
            return vector<int> ();
        }
    }
    
    vector<int> merge(vector<int> a, vector<int> b) {
        vector<int> res;
        size_t l = 0, r = 0;
        while (l < a.size() && r < b.size()) {
            res.push_back(a[l] < b[r] ? a[l++] : b[r++]);
        }
        
        while (l < a.size()) {
            res.push_back(a[l++]);
        }
        
        while (r < b.size()) {
            res.push_back(b[r++]);
        }
        return res;
    }
};

class Solution2 {
public:
    vector<int> mergeSort(vector<int> array) {
        vector<int> temp(array.size());
        merge_sort(array, 0, array.size() - 1, temp);
        return array;
    }
    
    void merge_sort(vector<int> &vec, int begin, int end, vector<int> &temp) {
        if (begin >= end) {
            return;
        }
        
        int mid = begin + (end - begin) / 2;
        merge_sort(vec, begin, mid, temp);
        merge_sort(vec, mid + 1, end, temp);
        merge(vec, begin, mid, end, temp);
    }
    
    void merge(vector<int> &vec, int l_st, int l_ed, int r_ed, vector<int> &temp) {
        int r_st = l_ed + 1, cur = l_st;
        int res_st = l_st;
        while(l_st <= l_ed && r_st <= r_ed) {
            temp[cur++] = (vec[l_st] <= vec[r_st]) ? vec[l_st++] : vec[r_st++];
        }
        while(l_st <= l_ed) {
            temp[cur++] = vec[l_st++];
        }
        while(r_st <= r_ed) {
            temp[cur++] = vec[r_st++];
        }
        while(res_st <= r_ed) {
            vec[res_st] = temp[i]; res_st++;
        }
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    test.mergeSort({5,4,3,2,1});
}