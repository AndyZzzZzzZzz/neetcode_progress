class Solution {
public:
    int countElements(vector<int>& arr) {
        
        int ans = 0;

        unordered_set<int> st;
        for(int i : arr) st.insert(i);
        for(int i : arr) if(st.find(i+1) != st.end()) ans++;

        return ans;
    }
};
