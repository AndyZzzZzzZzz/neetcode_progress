class Solution {
public:

   
    string longestPalindrome(string s) {
        // try to expand from each index and see if it forms a substring
        
        int ans = 1, n = s.size();
        int _l=0;

        for(int i =0; i < s.size(); ++i)
        {
           // odd len
           int l = i, r = i;
           while(l >=0 && r < n && s[l]==s[r])
           {
            l--; r++;
           }
           if(r-l-1 > ans)
           {
            ans = r-l-1; _l = l+1;
           }
           l = i; r = i +1;
            while(l >=0 && r < n && s[l]==s[r])
           {
            l--; r++;
           }
           if(r-l-1 > ans)
           {
            ans = r-l-1; _l = l+1;
           }

        }
        return s.substr(_l, ans);
    }
};
