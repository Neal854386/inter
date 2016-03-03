/*
Binary Tree Path Sum To Target
Fair
Data Structure
Given a binary tree in which each node contains an integer number. Determine if there exists a path from any node to any node (the two nodes can be the same node and they can only be on the path from root to one of the leaf nodes), the sum of the numbers on the path is the given target number.

Examples

    5

  /    \

2      11

     /    \

    6     14

If target = 17, There exists a path 11 + 6, the sum of the path is target,

*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : value(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  bool check(vector<int> input, int target) {
	int sum = 0;
	
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == target) {return true;}
	}
	
	for (int i = 0; i < input.size(); i++) {
		sum += input[i];
		if (sum == target) {return true;}
	}
	
	for (int i = 0; i < input.size() - 1; i++) {
		sum -= input[i];
		if (sum == target) {return true;}
	}
	
	return false;
  }

  bool exist(TreeNode* root, int target) {
	bool res = false;
	helper(root, target, res);
	return res;
  }

  void helper(TreeNode* root, int target, bool &res) {
    if (!root) {return;}
	path.push_back(root->value);
	if (!root->left && !root->right) {
		res = res || check(path, target);
	}
    helper(root->left,  target, res);
    helper(root->right, target, res);
    path.pop_back();
  }
 private:
	vector<int> path;
};


int main(int argc, char *argv[]) {
    Solution test;
    auto n1 = new TreeNode(3);
    auto n2 = new TreeNode(-8);
    auto n3 = new TreeNode(9);
    auto n4 = new TreeNode(4);
    auto n5 = new TreeNode(10);
    auto n6 = new TreeNode(2);
    auto n7 = new TreeNode(-5);
    auto n8 = new TreeNode(1);
    auto n9 = new TreeNode(-2);
    
    n1->left = n2;
    n1->right = n3;
  
    n2->left = n4;
    n2->right = n5;
    
    n3->left = n6;
    n3->right = n7;
    
    n4->left = n8;
    n4->right = n9;
    
 
    cout << test.exist(n1, -6) << endl;
	cout << test.exist(n1, -3) << endl;
	cout << test.exist(n1, 4) << endl;
	cout << test.exist(n1, 7) << endl;
}