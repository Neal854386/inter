/*Max Tree Show Result My Submissions


Given an integer array with no duplicates. A max tree building on this array is defined as follow:

The root is the maximum number in the array
The left subtree and right subtree are the max trees of the subarray divided by the root number.
Construct the max tree by the given array.
Example
Given [2, 5, 6, 0, 3, 1], the max tree is

              6

            /    \

         5       3

       /        /   \

     2        0     1

*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param A: Given an integer array with no duplicates.
     * @return: The root of max tree.
     */
    TreeNode* maxTree(vector<int> A) {
        // write your code here
        stack<TreeNode *> st;
        for(int v : A) {
           TreeNode *current = new TreeNode(v);
           if (!st.empty()) {
               TreeNode *top = st.top();
               while(!st.empty() && st.top()->val < v) {
                   top = st.top();
                   st.pop();
               }
    
               if (st.empty()) {
                   current->left = top;
               }
               else {
                   current->left = st.top()->right;
                   st.top()->right = current;
               }
           }
               
           st.push(current);
        }
        
        while(st.size() != 1) {
           st.pop();
        }
           
        return st.top();
    }
};
