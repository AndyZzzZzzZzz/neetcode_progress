class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) return false;

        map<int, int> mp;
        for(int i: hand) mp[i] ++;

        for(int i{}; i < (n / groupSize); ++i) {
            int start = mp.begin()->first;
            for(int j{}; j < groupSize; ++j) {
                if(mp.find(start) == mp.end()) return false;
                mp[start]--;
                if(mp[start] == 0) mp.erase(start);
                start++;
            }
        }
        return true;
    }
};
