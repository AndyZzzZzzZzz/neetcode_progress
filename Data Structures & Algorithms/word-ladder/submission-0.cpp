class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> nodes(wordList.begin(), wordList.end());
        unordered_set<string> seen;
        seen.insert(beginWord);

        if(nodes.find(endWord) == nodes.end()) return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while(!q.empty()) {
            auto [front, step] = q.front(); q.pop();
            if(front == endWord) return step;

            for(int i{}; i < front.size(); ++i) {
                for(char c='a'; c <= 'z'; ++c) {
                    string temp = front.substr(0,i) + c + front.substr(i+1, front.size());
             
                    if(!seen.count(temp) && nodes.count(temp)) {
                        q.push({temp, step+1});
                        seen.insert(temp);
                    }
                }
            }
        }
        return 0;
    }
};
