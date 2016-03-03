/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Jan 8, 2014
 Problem:    Sort List
 Difficulty: Medium
 Source:     http://oj.leetcode.com/problems/sort-list/
 Notes:
 Sort a linked list in O(nlogn) time using constant space complexity.

 Solution: merge sort.
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
   ListNode* cut_middle(ListNode* head) {
    auto slow = head;
    auto fast = head->next;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    auto ret = slow->next;
    slow->next = nullptr;
    return ret;
  }
  
  ListNode* merge(ListNode* l1, ListNode* l2) {
       ListNode dummy(0); dummy.next = nullptr;
       auto tail = &dummy;
       while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
       }
       if (!l1) tail->next = l2;
       if (!l2) tail->next = l1;
       return dummy.next;
  }
  
  ListNode* mergeSort(ListNode* head) {
    // write your solution here
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    
    auto mid = cut_middle(head);
    auto left_part = mergeSort(head);
    auto right_part = mergeSort(mid);
    return merge(left_part, right_part);
  }
};



class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: You should return the head of the sorted linked list,
                    using constant space complexity.
     */
    ListNode *sortList(ListNode *head) {
        // write your code here
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        auto mid = cut_middle(head);
        auto left_part = sortList(head);
        auto right_part = sortList(mid);
        
        return merge(left_part, right_part);
    }
    
    ListNode* cut_middle(ListNode* head) {
        auto fast = head, slow = head;
        while(fast && fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        auto ret = slow->next;
        slow->next = nullptr; // important for cut off the list
        return ret;
    }
    
    ListNode* merge(ListNode *l1, ListNode *l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->val < l2->val){
            l1->next = merge(l1->next, l2);
            return l1;
        } else {
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }
};



