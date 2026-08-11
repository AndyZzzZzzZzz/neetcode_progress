
struct Node {
    bool end;
    char c;
    std::array<Node*, 26> child{};
    Node(bool e, char chara) : c(chara), end(e) {}
};

class PrefixTree {
public:
    Node* root;
    PrefixTree() {
        root = new Node(false, ' ');
    }
    
    void insert(string word) {
        
        Node* tmp = root;
        for(char c : word) {
            int i = c- 'a';
            if(!tmp -> child[i]) tmp -> child[i] = new Node(false, c);
            tmp = tmp -> child[i];
        }
        tmp -> end = true;
    }
    
    bool search(string word) {
        Node* tmp = root;
        for(char c : word) {
            int i = c- 'a';
            if(!tmp -> child[i]) return false;
            tmp = tmp -> child[i];
        }
        return tmp -> end;
    }
    
    bool startsWith(string prefix) {
        Node* tmp = root;
        for(char c : prefix) {
            int i = c- 'a';
            if(!tmp -> child[i]) return false;
            tmp = tmp -> child[i];
        }
        return true;
    }
};
