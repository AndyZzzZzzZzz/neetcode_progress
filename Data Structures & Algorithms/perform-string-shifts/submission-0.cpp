class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        // simulation
        string ans = "";
        int pos = 0;
        for(auto v : shift)
        {
            if(v[0] == 0){
                ans += s.substr(v[1]);
                ans += s.substr(0, v[1]);
            }else
            {
                
                ans += s.substr(s.size() - v[1]);
                ans += s.substr(0, s.size() - v[1]);
            }
           
            s = ans;
            ans = "";
        }

       
       
        return s;
    }
};
