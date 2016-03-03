#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
      vector<int> quickSort(vector<int> array) {
           sort(array, 0, array.size() - 1);
           return array;
      }
  
      void sort(vector<int> &array, int start, int end) {
        if (start >= end) {
            return;
        }

        int pos = partition(array, start, end);
        sort(array, start, pos - 1);
        sort(array, pos + 1, end);
      }

    int partition(vector<int> &array, int st, int ed) {
        int pivot = st + (ed - st) / 2;
        swap(array[ed], array[pivot]); // put the pivot into end
        auto pivot_val = array[ed];
        // now array[ed] is pivot
        int pos = st;
        for (int cur = st; cur < ed; cur++) {
           if (array[cur] <= pivot_val) {
               swap(array[cur], array[pos]); pos++;
           }
        }

        swap(array[pos], array[ed]); // put the array[ed] back
        return pos;
    }
};

int main(int argc, char *argv[]) {
    class Solution test;
    auto res = test.quickSort({3,4,2,1,3,3,3,9,0});
    for (auto i : res) {
        cout << i << "|";
    }
}