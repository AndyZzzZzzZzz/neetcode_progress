class Solution {
public:

    string encode(vector<string>& strs) {
        /*
            Encoding algorithm: length of character + separator + actual string
        */

        string ans;

        for(const string& s : strs)
        {
            ans += (to_string(s.size()) + '/' + s);
        }
        return ans;
    }

    vector<string> decode(string s) {

        vector<string> ans;

        while(s.size() > 0)
        {
            //cout << s << endl;
            auto ptr = s.find('/');
            //cout << ptr <<endl;
            int total = s.substr(0, ptr).size();
            int size = stoi(s.substr(0, ptr)) ;
            ans.push_back(s.substr(ptr + 1, size));
            s.erase(0, size + 1 + total);
            //cout << s << endl;
        }
        return ans;
    }
};
