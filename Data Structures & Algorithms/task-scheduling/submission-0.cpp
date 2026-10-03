class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // greedily process the most frequent task first
        priority_queue<int> pq;
        unordered_map<char, int> mp;
        for(char c : tasks) mp[c]++;
        for(auto& p : mp) pq.push(p.second);

        int time = 0;
        queue<vector<int>> q;

        while(!pq.empty() || !q.empty()) {
            // grab back the elements finished cool down
            while(!q.empty() && q.front()[1] < time) {
                pq.push(q.front()[0]);
                q.pop();
            }
            // process most frequent element first
            if(!pq.empty()){
                int freq = pq.top(); pq.pop();
                freq--;
                if(freq != 0) q.push({freq, time + n});
            }
            time++;
            
        }


        return time;

    }
};
