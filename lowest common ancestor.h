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
     * @param root: The root of the binary search tree.
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
        // write your code here
        if (!root) {return nullptr;}
        if (root == A || root == B) {return root;}
        TreeNode *L = lowestCommonAncestor(root->left, A, B);
        TreeNode *R = lowestCommonAncestor(root->right, A, B);
        if (L && R) return root;
        return L ? L : R;
    }
};

// have parent
class Solution {
    int getHeight(TreeNode *p) { int height = 0;
        while (p) {
            height++;
            p = p->parent;
        }
        return height;
    }

    TreeNode *LCA(TreeNode *p, TreeNode *q) {
        int h1 = getHeight(p), h2 = getHeight(q);
        if (h1 > h2) {
            swap(h1, h2);
            swap(p, q);
        }
        int dh = h2 - h1;
        for (int h = 0; h < dh; h++)
            q = q->parent;
       
        while (p && q) {
            if (p == q) return p;
            p = p->parent;
            q = q->parent;
        }
        return nullptr;
    }

};

// if it is BST
class Solution {
public:

    TreeNode *LCA(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root || !p || !q) {return nullptr;}
        if (max(p->val, q->val) < root->val) {
            return LCA(root->left, p, q);
        }
        else if (min(p->val, q->val) > root->val) {
            return LCA(root->right, p, q);
        }
        else {
            return root;
        }
    }
}