class Solution {
public:
    bool canPermutePalindrome(string s) {
        // similar check that we have at most one odd character
        int arr[26] = {0};

        for(char c : s) arr[c - 'a']++;

        bool check = true;
        for(int i{}; i < 26; ++i)
        {
            if(arr[i] % 2 == 1)
            {
                if(check) check = false;
                else return false;
            }
        }
        return true;

    }
};
