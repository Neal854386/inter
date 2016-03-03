/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 10, 2013
 Update:     Jul 29, 2013
 Problem:    Convert Sorted List to Binary Search Tree
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_109
 Notes:
 Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

 Solution: 1. Recursion. Pre-order. A very good Idea. O(n)
           2. Recursion, Binary Search.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


 class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == nullptr) {return nullptr;}
        return sortedListToBSTRe(head, 0, getLength(head) - 1);
    }
    
    TreeNode *sortedListToBSTRe(ListNode *&node, int start, int end) {
        if (start > end) {return NULL;}
        int mid = start + (end - start) / 2;
        
        auto *leftChild = sortedListToBSTRe(node, start, mid - 1);
        
        auto *root = new TreeNode(node->val);
        node = node->next;
        
        auto *rightChild = sortedListToBSTRe(node, mid + 1, end);
        
        root->left = leftChild;
        root->right = rightChild;
        return root;
    }
    
    int getLength(ListNode *head) {
        int length = 0;
        while (head) {
            length++;
            head = head->next;
        }
        return length;
    }
};


class Solution {
public:
    TreeNode *sortedListToBST_1(ListNode *head) {
        return sortedListToBSTRe(head, getLength(head));
    }
    
    TreeNode *sortedListToBSTRe(ListNode *&head, int length)
    {
        if (length == 0) return NULL;
        int mid = length / 2;
        TreeNode *left = sortedListToBSTRe(head, mid);
        TreeNode *root = new TreeNode(head->val);
        TreeNode *right = sortedListToBSTRe(head->next, length - mid - 1);
        root->left = left;
        root->right = right;
        head = head->next;
        return root;
    }
    
    int getLength(ListNode *head)
    {
        int length = 0;
        while (head)
        {
            length++;
            head = head->next;
        }
        return length;
    }

    TreeNode *sortedListToBST_2(ListNode *head) {
        if(head==nullptr) return nullptr;
        if(head->next==nullptr) return new TreeNode(head->val);
        ListNode * slow = head;
        ListNode * fast = head;
        ListNode * pre = nullptr;
        while(fast->next&&fast->next->next){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        TreeNode * node = new TreeNode(slow->val);
        if(pre){
            pre->next = nullptr;
            node->left = sortedListToBST(head);
        }
        node->right = sortedListToBST(fast);
        return node;
    }
};



class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode *sortedListToBST(ListNode *head) {
        // write your code here
        return list_to_tree(head, nullptr); 
    }
    
    TreeNode * list_to_tree(ListNode *begin, ListNode *end) {
        if(begin == nullptr || begin == end)
            return nullptr;
        
        if (begin->next == end)
            return new TreeNode(begin->val);
        
        auto mid = middle(begin, end);
        auto root = new TreeNode(mid->val);
        root->left = list_to_tree(begin, mid);
        root->right = list_to_tree(mid->next, end);
        return root;
    }
    
    ListNode* middle(ListNode* nd, ListNode* end) {
        auto fast = nd, slow = nd;
        while (fast != end && fast->next != end) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};

