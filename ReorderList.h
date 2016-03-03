/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Nov 11, 2013
 Problem:    Reorder List
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/reorder-list/
 Notes:
 Given a singly linked list L: L0->L1->...->Ln-1->Ln,
 reorder it to: L0->Ln->L1->Ln-1->L2->Ln-2->...
 You must do this in-place without altering the nodes' values.
 For example,
 Given {1,2,3,4}, reorder it to {1,4,2,3}.

 Solution: Reverse the back half first, then reorder.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode *head) {
        if (!head || !head->next) return;
        ListNode *slow = head, *fast = head->next->next;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast) slow = slow->next;
        ListNode *mid = slow, *cur = slow->next;
        while (cur->next) {
            ListNode *mov = cur->next;
            cur->next = mov->next;
            mov->next = mid->next;
            mid->next = mov;
        }
        cur = head;
        while (cur != mid && mid->next) {
            ListNode *mov = mid->next;
            mid->next = mov->next;
            mov->next = cur->next;
            cur->next = mov;
            cur = cur->next->next;
        }
    }
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return;
        }   
        
        auto mid = find_middle(head);
        auto last = reverseList(mid->next);
        mid->next = nullptr;
        merge(head, last);
    }
    
    void merge (ListNode *head1, ListNode *head2) {
        int index = 0;
        auto dummy = new ListNode(0);
        while (head1 != nullptr && head2 != nullptr) {
            if (index % 2 == 0) {
                dummy->next = head1;
                head1 = head1->next;
            } else {
                dummy->next = head2;
                head2 = head2->next;
            }
            dummy = dummy->next;
            index++;
        }
        
        if (head1 != nullptr) {
            dummy->next = head1;
        } else {
            dummy->next = head2;
        }    
    }
    
    ListNode* find_middle(ListNode *head) {
        ListNode* fast = head->next, *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    ListNode* reverseList(ListNode *head) {
        ListNode* prev = nullptr;
        while (head != nullptr) {
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
};