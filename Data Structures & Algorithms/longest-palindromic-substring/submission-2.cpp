class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.size();
        if (n <= 1 ) return s;

        int start = 0, ans = 1;

        auto expand = [&](int l, int r)
        {
            while(l >=0 && r < n && s[l]==s[r])
            {
                int curr = r -l+1;
                if(curr > ans)
                {
                    ans = curr;
                    start = l;
                }
                l--; r++;
            }
        };

        for(int i=0; i < n; ++i)
        {
            expand(i, i);
            expand(i,i+1);
        }
        return s.substr(start,ans);
    }
};
