
 * Definition for a binary tree node.
 * struct TreeNode {
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };


class Codec {
private:
    void enc(TreeNode *root, string &s) {
        if (!root) {
            s += "# ";
            return;
        s += to_string(root->val) + " ";
        enc(root->left, s);
        enc(root->right, s);
    TreeNode *dec(int &idx, string &data) {
        if (idx == data.length()) {
            return 0;
        }
        if (data[idx] == '#') {
            idx += 2;
            return 0;
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
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        string s = "";
        enc(root, s);
        return s;
    TreeNode* deserialize(string data) {
        int idx = 0;
        return dec(idx, data);
