class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()) return false;
        // O(N) sliding window approach
        vector<int> arr(24, 0); 

        for(char c : s1) arr[c-'a']++;

        vector<int> arr2(24, 0);

        int l = 0;
        for(int r =0; r < s2.size(); r++)
        {
            arr2[s2[r] - 'a'] ++;
            while(arr2[s2[r] - 'a'] > arr[s2[r] - 'a'])
            {
                arr2[s2[l++] - 'a']--;
            }
            if(arr2 == arr) return true;
        }
        return false;
        
    }
};
