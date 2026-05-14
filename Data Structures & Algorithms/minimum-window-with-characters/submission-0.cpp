class Solution {
public:
    string minWindow(string s, string t) {
        
        // sliding window: attempt to shrink window at every iteration
        unordered_map<char, int> mp, mp2;
        for(auto c : t) mp[c]++;

        int l = 0;
        int ans = numeric_limits<int>::max();
        int al=0;

        for(int r=0; r < s.size(); ++r)
        {
            char c = s[r];
            if(mp.find(c) == mp.end()) continue;

            mp2[c]++;
            
            bool check = true;
            for(const auto& p : mp)
            {
                if(!mp2.count(p.first) || p.second > mp2[p.first])
                {
                    check = false;
                    break;
                }
            }

            while(true)
            {
                char remove = s[l];
                if(!mp.count(remove))
                {
                    l++;
                }
                else if(mp2[remove] > mp[remove]){
                    if(mp2[remove]-- == 0) mp2.erase(remove);
                    l++;
                }else
                {
                    break;
                }
            }

            if(check && (ans > (r-l+1)))
            {
                ans = r-l+1;
                al = l;
            }
        }

        return (ans == numeric_limits<int>::max()) ? "" : s.substr(al, ans);
    }
};
