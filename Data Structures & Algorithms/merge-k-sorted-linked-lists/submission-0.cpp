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

class Compare {
    public:
        bool operator()(ListNode* a, ListNode* b) {
            // true means order is not correct
            if(a -> val > b -> val) return true;
            return false;
        }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // use a min heap
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        ListNode dummy;
        ListNode* curr = &dummy;

        for(auto& node : lists) pq.push(node);

        while(!pq.empty()) {
            auto n = pq.top(); pq.pop();
            curr -> next = n;
            curr = curr -> next;
            if(n -> next) pq.push(n -> next);
        }
        return dummy.next;
    }
};
