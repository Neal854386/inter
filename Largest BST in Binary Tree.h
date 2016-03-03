/*

333. Largest BST Subtree

// http://articles.leetcode.com/2010/11/largest-binary-search-tree-bst-in_22.html

Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), 
where largest means subtree with largest number of nodes in it.

Note:
A subtree must include all of its descendants.
Here's an example:
    10
    / \
   5  15
  / \   \ 
 1   8   7
The Largest BST Subtree in this case is the highlighted one. 
The return value is the subtree's size, which is 3.

*/



struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
struct Part {
public:
	int max, min, size;
	bool isBST;
	Part():max(INT_MIN), min(INT_MAX), size(0), isBST(true) {}
};

class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        auto res = getLargestBST(root);
        return res.size;
    }
    
    Part getLargestBST(TreeNode* root) {
        Part res;
        //if root is null return min as MAX and max as MIN 
        if (!root) {return res;}

        auto leftPart = getLargestBST(root->left);
        auto rightPart = getLargestBST(root->right);
        int val = root->val;
        int size = 1, max_val = 0, min_val = 0;
        if (!leftPart.isBST || !rightPart.isBST || (leftPart.max >= val || rightPart.min <= val)) {
            res.isBST = false;
            res.size = max(leftPart.size, rightPart.size);
			return res;
        }
        res.size = leftPart.size + rightPart.size + 1;
        res.min = root->left != nullptr ? leftPart.min : val;
        res.max = root->right != nullptr ? rightPart.max : val;
        return res;
	}
};


int main(int argc, char *argv[]) {
 	TreeNode* root = new TreeNode(1);
	TreeNode* node1 = new TreeNode(-1);
	TreeNode* node2= new TreeNode(2);
	root->left = node1;
	root->right = node2;
	Solution test;
	cout << test.largestBSTSubtree(root);
}

int ans = 0;

struct Part {
 public:
    int max, min, size;
    bool isBST;
    Part():max(INT_MIN), min(INT_MAX), size(0), isBST(false) {}
    void set(int max, int min, int size) {
        this.max = max, this.min = min, this.size = size;
    }
};

Part getLargestBST(node* root) {
    Part res;
    if (!root) {return res;}
    //postorder traversal of tree. First visit left and right then
    //use information of left and right to calculate largest BST.
    auto leftPart = getLargestBST(root->left);
    auto rightPart = getLargestBST(root->right);
    int val = root->val;

    //if either of left or right subtree says its not BST or the data
    //of this node is not greater/equal than max of left and less than min of right
    //then subtree with this node as root will not be BST. 
    //Return false and max size of left and right subtree to parent
    if (!leftPart.isBST || !rightPart.isBST || leftPart.max > val || rightPart.min < val) {
        res.isBST = false;
        res.size = max(leftPart.size, rightPart.size);
        return res;
    }

    //if we reach this point means subtree with this node as root is BST.
    //Set isBST as true. Then set size as size of left + size of right + 1.
    //Set min and max to be returned to parent.
    res.size = leftPart.size + rightPart.size + 1;
    //if root.left is null then set root.data as min else
    //take min of left side as min
    res.min = root->left != nullptr ? leftPart.min : val;
  
    //if root.right is null then set root.data as max else
    //take max of right side as max.
    res.max = root->right != nullptr ? rightPart.max : val;

    return res;
}

       