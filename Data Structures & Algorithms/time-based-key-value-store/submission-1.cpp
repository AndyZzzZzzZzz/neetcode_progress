

class TimeMap {

private:
    unordered_map<string, vector<pair<int, string>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        
        if(mp.find(key) == mp.end()) return "";

        auto it = upper_bound(mp[key].begin(), mp[key].end(), timestamp,
        [](int t, const pair<int, string>& e){ return t < e.first; });

       
        if(it == mp[key].begin()) return "";
        return prev(it) -> second;
        
        }
};
