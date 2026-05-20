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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* tmp = head;
        while(tmp){ size++; tmp = tmp -> next; }
        
        // fast slow pointer: fast pointer runs n step ahead
        ListNode* slow = nullptr;
        ListNode* fast = head;
        n = size - n;
        if(n == 0) return head -> next;

        for(int i=0; i < n; ++i)
        {
            slow = fast; fast = fast -> next;
        }
        slow -> next = fast -> next;
        return head;
    }
};
