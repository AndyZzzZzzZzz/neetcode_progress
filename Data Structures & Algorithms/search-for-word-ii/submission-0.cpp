struct Node {
    char c;
    vector<Node*> child;
    bool is_end;
    int idx;
    Node(char ch, bool end) : c(ch), child(26,nullptr), is_end(end) {}
};


class WordDictionary {
public:
    Node* root = new Node('*', false);
    WordDictionary() {
        
    }
    
    void addWord(string word, int i) {
        Node* tmp = root;
        for(char c : word) {
            int idx = c - 'a';
            if(!tmp->child[idx]) tmp -> child[idx] = new Node(c, false);
            tmp = tmp->child[idx];
        }
        tmp -> is_end = true;
        tmp -> idx = i;
    }
};

class Solution {
private:
    // private methods to search around the trie
    WordDictionary* dict = new WordDictionary();

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(int i{}; i < words.size(); ++i) {
            dict -> addWord(words[i], i);
        }

        vector<string> ans;
        int x[4] = {1,-1,0,0};
        int y[4] = {0,0,-1,1};
        int n = board.size(), m= board[0].size();
        function<void(Node*,int,int)> dfs = [&](Node* curr, int i,int j){
            if(curr -> is_end) {
                ans.push_back(words[curr->idx]);
                curr->is_end = false;
            }
            char o = board[i][j];
            board[i][j] = '*';
            for(int d{}; d < 4; ++d) {
                int ni = x[d] +i, nj = y[d] + j;
                if(ni >=0 && nj >= 0 && ni < n && nj < m && board[ni][nj] != '*') {
                    int idx = board[ni][nj] - 'a';
                    if(curr -> child[idx]) {
                        dfs(curr -> child[idx], ni, nj);
                    }
                }
            }
            // backtrack
            board[i][j] = o;

        };

        
        Node* curr = dict->root;
        for(int i{}; i < n; i++) {
            for(int j{}; j < m; ++j) {
                int idx = board[i][j] - 'a';
                if(curr->child[idx]) dfs(curr->child[idx], i,j);
            }
        }
        return ans;

    }
};
