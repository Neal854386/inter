/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 10, 2013
 Update:     Sep 27, 2013
 Problem:    Remove Duplicates from Sorted List II
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_82
 Notes:
 Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
 For example,
 Given 1->2->3->3->4->4->5, return 1->2->5.
 Given 1->1->1->2->3, return 2->3.

 Solution: 1. iterative 2. recursive
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
    ListNode *deleteDuplicates(ListNode *head) {
        return deleteDuplicates_1(head);
    }
    
    ListNode *deleteDuplicates_1(ListNode *head) {
        ListNode dummy(0), *cur = &dummy;
        dummy.next = head;
        while (cur->next)
        {
            ListNode *node = cur->next;
            int val = node->val;
            if (!node->next || node->next->val != val) {
                cur = cur->next;
                continue;
            }
            while (node && node->val == val) {
                ListNode *del = node;
                node = node->next;
                delete del;
            }
            cur->next = node;
        }
        return dummy.next;
    }
    
    ListNode *deleteDuplicates_2(ListNode *head) {
        if (!head) return NULL;
        if (!head->next || head->val != head->next->val) {
            head->next = deleteDuplicates(head->next);
            return head;
        }
        int val = head->val;
        while(head && head->val == val) {
            ListNode *del = head;
            head = head->next;
            delete del;
        }
        return deleteDuplicates(head);
    }
};


class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head || !head->next) {
            return head;
        }
        auto dummy = new ListNode(0); dummy->next = head;
        auto cur = dummy;
        
        while (cur->next != NULL && cur->next->next != NULL) {
            if (cur->next->val == cur->next->next->val) {
                int val = cur->next->val;
                while (cur->next != NULL && cur->next->val == val) {
                    auto del = cur->next;
                    cur->next = cur->next->next;
                    delete del;
                }            
            } else {
                cur = cur->next;
            }
        }
        
        return dummy->next;
    }
};