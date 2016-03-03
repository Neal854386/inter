/*
Closest Binary Search Tree Value My Submissions Question
Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Note:
Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        auto *cur = root;
        double res = cur->val;
        while (cur) {
            res = abs(target - cur->val) < abs(target - res) ? cur->val : res;
            if (target > cur->val) {
                cur = cur->right;
            } else if (target < cur->val) {
                cur = cur->left;
            } else if (target == cur->val){
                return cur->val;
            }
        }
        return res;
    }
};

class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int ans = -1;
        double dif = ULLONG_MAX;
        while (root) {
            int v = root->val;
            if (v < target) {
                if (target - v < dif)
                    ans = v, dif = target - v;
                root = root->right;
            } else if (v > target) {
                if (v - target < dif)
                    ans = v, dif = v - target;
                root = root->left;
            } else {
                return v;
            }
        }
        return ans;
    }
};