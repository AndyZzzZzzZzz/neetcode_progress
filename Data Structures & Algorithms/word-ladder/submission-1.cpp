class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> nodes(wordList.begin(), wordList.end());

        if(nodes.find(endWord) == nodes.end()) return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while(!q.empty()) {
            auto [front, step] = q.front(); q.pop();
            if(front == endWord) return step;

            for(int i{}; i < front.size(); ++i) {
                for(char c='a'; c <= 'z'; ++c) {
                    char ch = front[i];
                    front[i] = c;
                    if(nodes.count(front)) {
                        q.push({front, step+1});
                        nodes.erase(front);
                    }
                    front[i] = ch;
                }
            }
        }
        return 0;
    }
};
