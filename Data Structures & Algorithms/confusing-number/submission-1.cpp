class Solution {
public:
    bool confusingNumber(int n) {
        // number has to be reversed after 180 rotation
        int x = n;
        bool valid = false;
        int ans = 0;
        while(x)
        {
            int r = x % 10; x/=10;
            if(r==2 || r==3 || r==4 || r==5 || r==7) return false;
            
            if(r == 6) r = 9;
            else if(r == 9) r = 6;
            ans *= 10;
            ans += r;
        }
        return ans != n;
    }
};
