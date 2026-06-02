/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // copy linked list without a hash table
        // interleaving nodes method

        if(!head) return head;

        Node* curr = head;
        while(curr)
        {
            Node* next = curr -> next;
            curr -> next = new Node(curr -> val);
            curr -> next -> next = next;
            curr = next;
        }

        curr = head;
        while(curr)
        {
            if(curr -> random) curr -> next -> random = curr -> random -> next;
            curr = curr -> next -> next;
        }

        curr = head;
        Node dummy(0);
        Node* ans = &dummy;
        while(curr)
        {
            Node* node = curr -> next;

            ans -> next = node;
            ans = node;

            curr -> next = ans -> next;

            curr = curr -> next;
        }
        return dummy.next;
    }
};
