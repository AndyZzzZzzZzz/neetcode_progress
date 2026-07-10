struct Node {
    int val;
    Node* next;
    Node(int v, Node* n) : val(v), next(n) {}
};


class LinkedList {
private:
Node* head;
int size;
public:
    LinkedList() : head(nullptr), size(0) {

    }

    int get(int index) {
        if(index >= size) return -1;

        Node* curr = head;
        for(int i{}; i < index; ++i) {
            curr = curr -> next;
        }
        return curr -> val;
    }

    void insertHead(int val) {
        size++;
        if(!head){ head = new Node(val, nullptr); return;}
        Node* node = new Node(val, head);
        head = node;
    }
    
    void insertTail(int val) {
        size++;
        if(!head){ head = new Node(val, nullptr); return;}
        Node* ptr = head;
        while(ptr -> next) ptr = ptr -> next;
        ptr -> next = new Node(val, nullptr);
    }

    bool remove(int index) {
        
        if(index < 0 || index >= size) return false;
        if(index == 0) {
            Node* tmp = head;
            head = head -> next;
            delete tmp;
        }else{
            Node* ptr = head;
            for(int i{}; i < index-1; ++i) {
                ptr = ptr -> next;
            }
            Node* tmp = ptr -> next;
            ptr -> next = tmp -> next;
            delete tmp;
        }
        size--;
        return true;
    }

    vector<int> getValues() {
        vector<int> ans(size);
        Node* ptr = head;
        for(int i{}; i < size; ++i) {
            ans[i] = ptr -> val;
            ptr = ptr -> next;
        }
        return ans;

    }
};
