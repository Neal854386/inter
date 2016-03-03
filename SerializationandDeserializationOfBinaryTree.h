/*
Serialization and Deserialization Of Binary Tree

Design an algorithm and write code to serialize and deserialize a binary tree. Writing the tree to a file is called 'serialization' and reading back from the file to reconstruct the exact same binary tree is 'deserialization'.

There is no limit of how you deserialize or serialize a binary tree, you only need to make sure you can serialize a binary tree to a string and deserialize this string to the original structure.

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
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode *root) {
        // write your code here
        if (root == nullptr) {
            res_str.push_back('#');
        } else {
            res_str.push_back(root->val + '0');
            serialize(root->left);
            serialize(root->right);
        }
        return res_str;
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode *deserialize(string data) {
        // write your code here
		int index = 0;
		return deserialize_hepler(data, index);
    }

    TreeNode* deserialize_hepler(string data, int &index) {
        if (data.empty() || data[index] == '#') {
            return nullptr;
        }
        auto new_node = new TreeNode(data[index] - '0');
		index++;
        new_node->left = deserialize_hepler(data, index);
		index++;
        new_node->right = deserialize_hepler(data, index);
        return new_node;
    }

private:
    string res_str = "";
};


class Solution {
public:
    /**
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode *p, ostream &out) {
            if (!p) {
                out << "# ";
            } else {
            out << p->data << " ";
            writeBinaryTree(p->left, out);
            writeBinaryTree(p->right, out);
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */

    void deserialize_hepler(TreeNode *p, ifstream &fin) {
        char token;
        fin >> token;
        if (token == '#') {
                return;
        }
        
        new_node = new BinaryTree(token - '0');
        readBinaryTree(new_node->left, fin);
        readBinaryTree(new_node->right, fin);
    }



private:
    string res_str = "";
};





