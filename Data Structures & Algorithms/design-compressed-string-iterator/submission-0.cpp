class StringIterator {
private:
    vector<pair<char, int>> v;
    int pos;

public:
    StringIterator(string compressedString) : pos(0) {
        
        string s = compressedString;
        int i{};
        while(i < s.size())
        {
            int j = i + 1;
            while(j < s.size() && isdigit(s[j])) ++j;
            int val = stoi(s.substr(i+1, j - i));
            v.push_back({s[i], val});
            i = j;
        }
    }
    
    char next() {
        if(pos >= v.size()) return ' ';

        int c = v[pos].first;
        if(--v[pos].second == 0) ++pos;
        return c;
    }
    
    bool hasNext() {
        return pos < v.size();
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
