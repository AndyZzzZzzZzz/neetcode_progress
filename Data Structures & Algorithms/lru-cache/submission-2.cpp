struct Node {
    int val;
    int key;
    Node* next;
    Node* prev;
    Node(int v, int k, Node* n, Node* p) : val(v), key(k), next(n), prev(p) {}
};


class LRUCache {
private:
    // map 1: key -> value node
    unordered_map<int, Node*> mp1;
    // head: tracks the most recently added node
    // tail: tracks the least recent added node
    Node* head;
    Node* tail;
    int size;

    void add(int x, int v) {
        Node* nxt = head -> next;
        head -> next = new Node(v, x, nxt, head);
        if(nxt) nxt -> prev = head -> next;
        mp1[x] = head -> next;
    }

    void remove() {
        Node* targ = tail -> prev;
        targ -> prev -> next = targ -> next;
        tail -> prev = targ -> prev;
        
        int k = targ -> key;
        mp1.erase(k);
        delete targ;
    }

    void update(int x) {
        Node* targ = mp1[x];
        targ -> prev -> next = targ -> next;
        targ -> next -> prev = targ -> prev;

        targ -> next = head -> next;
        targ -> prev = head;
        head -> next -> prev = targ;
        head -> next = targ;
    }

public:
    LRUCache(int capacity) : size(capacity){
        head = new Node(-1, -1, nullptr, nullptr);
        tail = new Node(-1, -1, nullptr, nullptr);
        head -> next = tail;
        tail -> prev = head;
    }
    
    int get(int key) {
        if(mp1.count(key)) {
            update(key);
            return mp1[key] -> val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp1.count(key)) {
            mp1[key] -> val = value;
            update(key);
            return;
        }
        add(key, value);
        if(mp1.size() > size) remove();
    }
};
