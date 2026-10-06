class Twitter {
private: 
    unordered_map<int, unordered_set<int>> mp;
    unordered_map<int, vector<pair<int, int>>> tweets;
    int count = 0;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({count++, tweetId});
        mp[userId].insert(userId);
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>> pq; // max heap sort by count
        for(auto& user : mp[userId]) {
            if(tweets.find(user) == tweets.end()) continue;
            int n = tweets[user].size();
            auto [count, tid] = tweets[user][n-1];
            pq.push({count, tid, n-1, user});
        }

        vector<int> ans;
        while(!pq.empty() && ans.size() < 10) {
            auto v = pq.top(); pq.pop();
            ans.push_back(v[1]);
            int pos = v[2];
            int user = v[3];
            if(pos > 0) {
                auto [c, t] = tweets[user][--pos];
                pq.push({c,t,pos, user}); 
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        mp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(mp[followerId].find(followeeId) != mp[followerId].end()) {
            mp[followerId].erase(followeeId);
        }
    }
};
