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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode dummy(0);
        ListNode* ans = &dummy;

        while(list1 || list2)
        {
            int a = numeric_limits<int>::max(), b = numeric_limits<int>::max();
            if(list1) a = list1 -> val;
            if(list2) b = list2 -> val;
            ans -> next = new ListNode(min(a, b));
            ans = ans -> next;
            if(ans -> val == a) list1 = list1 -> next;
            else list2 = list2 -> next;
        }
        return dummy.next;
    }
};
