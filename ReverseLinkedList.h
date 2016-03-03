/*

Reverse Linked List Show Result My Submissions

Reverse a linked list.

Example
For linked list 1->2->3, the reversed linked list is 3->2->1

Challenge
Reverse it in-place and in one-pass

*/


/**
 * Definition of ListNode
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 * 
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: The new head of reversed linked list.
     */
    ListNode *reverse(ListNode *n) {
        // write your code here
        ListNode prev = null;
        while (head != null) {
            ListNode temp = head.next;
            head.next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
};

class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: The new head of reversed linked list.
     */
    ListNode *reverse(ListNode *n) {
        // write your code here
        if (n == nullptr || n->next == nullptr) return n;  
        // so we grab the second element (which will be the last after we reverse it)
        ListNode* secondElem = n->next;
        // bug fix - need to unlink list from the rest or you will get a cycle
        n->next = nullptr;
        // then we reverse everything from the second element on
        ListNode* reverseRest = reverse(secondElem);
        // then we join the two lists
        secondElem->next = n;
        return reverseRest;
    }
};
