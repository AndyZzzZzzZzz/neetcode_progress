struct Node {
    char c;
    vector<Node*> child;
    bool is_end;
    Node(char ch, bool end) : c(ch), child(26,nullptr), is_end(end) {}
};


class WordDictionary {
private:
    Node* root = new Node('*', false);
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        Node* tmp = root;
        for(char c : word) {
            int idx = c - 'a';
            if(!tmp->child[idx]) tmp -> child[idx] = new Node(c, false);
            tmp = tmp->child[idx];
        }
        tmp -> is_end = true;
    }
    
    bool search(string word) {
        Node* tmp = root;
        for(int i{}; i < word.size(); ++i) {
            char c = word[i];
            if(isalpha(c)){
                int idx = c - 'a';
                if(!tmp->child[idx]) return false;
                tmp = tmp->child[idx];
            }else {
                for(char ch='a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if(search(word)) return true; 
                }
                return false;
            }
        }
        return tmp -> is_end;
    }
};
