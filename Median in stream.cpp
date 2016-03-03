#include <iostream>
#include <queue>
using namespace std;

/*

1. 维持两个heap,一个是最小堆，一个是最大堆。

2. 一直使maxHeap的size大于minHeap.

3. 当两边size相同时，比较新插入的value,如果它大于minHeap的最小值，把它插入到minHeap。并且把minHeap的最小值移动到maxHeap。

*/

class Solution {
public:
    // maintains a condition that maxHeap.size() >= minHeap.size()
    void Insert(int value) {
        if(maxHeap.empty()) {  
            maxHeap.push(value);  
            return;  
        }

        if(minHeap.empty()){  
            minHeap.push(value);  
            return;  
        } 

        if(minHeap.size() == maxHeap.size()) {
               if (value > minHeap.top()) {
                   maxHeap.push(minHeap.top());
                   minHeap.pop();
                   minHeap.push(value);
               } else {
                   maxHeap.push(value);
               }

        } else {
               if (value < maxHeap.top()) {
                   minHeap.push(maxHeap.top());
                   maxHeap.pop();
                   maxHeap.push(value);
               } else {
                   minHeap.push(value);
               }
        }
    }

    double GetMedian() {
        int size = minHeap.size() + maxHeap.size();
        double median = 0;
        if (size == 1 && !maxHeap.empty()) {return maxHeap.top();}
        cout << minHeap.top() << "|" << maxHeap.top() << endl;
        if (size % 2 == 0 && !maxHeap.empty() && !minHeap.empty()) 
            median = (double)(minHeap.top() + maxHeap.top()) / 2;
        else if (!minHeap.empty())
            median = (double)maxHeap.top();

        return median;
    }

private:
    priority_queue<int, vector<int>, greater<int> > minHeap;
    priority_queue<int, vector<int>, less<int> > maxHeap;
};

int main(int argc, char *argv[]) {
	  Solution test;
    test.Insert(1);
    //cout << test.GetMedian() << endl;
    test.Insert(2);
    //cout << test.GetMedian() << endl;
    test.Insert(3);
    cout << test.GetMedian() << endl;

}