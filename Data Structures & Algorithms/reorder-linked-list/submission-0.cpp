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
    void reorderList(ListNode* head) {
        if(!head) return;
        // separate list
        ListNode* fast = head -> next;
        ListNode* slow = head;
        while(fast && fast -> next)
        {
            fast = fast -> next -> next;
            slow = slow -> next;
        }

        ListNode* shead = slow -> next;
        slow -> next = nullptr;

        // reverse list
        ListNode* prev = nullptr;
        while(shead)
        {
            ListNode* nxt = shead -> next;
            shead -> next = prev;
            prev = shead;
            shead = nxt;
        }

        // merge list
        // merging prev + head
        ListNode* first = head;
        ListNode* second = prev;

        while(second)
        {
            ListNode* t1 = first -> next;
            ListNode* t2 = second -> next;
            first -> next = second;
            second -> next = t1;
            first = t1;
            second = t2;
        }
        
 
    }
};
