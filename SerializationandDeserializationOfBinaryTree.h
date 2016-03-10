/*
297. Serialize and Deserialize Binary Tree
Difficulty: Medium
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, 
or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. 
There is no restriction on how your serialization/deserialization algorithm should work. 
You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

For example, you may serialize the following tree

    1
   / \
  2   3
     / \
    4   5
as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
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


class Codec {
private:
    void enc(TreeNode *root, string &s) {
        if (!root) {
            s += "# ";
            return;
        }

        s += to_string(root->val) + " ";
        enc(root->left, s);
        enc(root->right, s);
    }

    TreeNode *dec(int &idx, string &data) {
        if (idx == data.length()) {
            return 0;
        }
        if (data[idx] == '#') {
            idx += 2;
            return 0;
        }

        int r = idx;
        // find last char for a value
        while (data[r] != ' ')
            r++;
        int val = stoi(data.substr(idx, r - idx));
        idx = r + 1;

        TreeNode *root = new TreeNode(val);
        root->left = dec(idx, data);
        root->right = dec(idx, data);

        return root;
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        string s = "";
        enc(root, s);
        return s;
    }

    TreeNode* deserialize(string data) {
        int idx = 0;
        return dec(idx, data);
    }
};
