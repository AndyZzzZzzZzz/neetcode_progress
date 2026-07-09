/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode dummy;
        ListNode* back = &dummy;
       

        ListNode* ptr = head;
        while(ptr) {
            // reverse nodes in-place
            // check if we still have remaining lists
            ListNode* curr = ptr;
            for(int i{}; i < k; ++i) { 
                if(!curr) return dummy.next;
                curr = curr -> next;
            }

            // reverse
            ListNode* prev = curr;
            ListNode* gTail = ptr;

            for(int i{}; i < k; ++i) {
                ListNode* nxt = ptr -> next;
                ptr -> next = prev;
                prev = ptr;
                ptr = nxt;
            }
            back -> next = prev;
            back = gTail;
        }
        return dummy.next;
    }
};
