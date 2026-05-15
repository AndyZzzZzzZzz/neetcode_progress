class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // binary search on the solution
        int l = 1, r= *max_element(piles.begin(), piles.end());

        function<bool(int)> check = [&](int rate)
        {
            int time = 0;
            for(int b : piles )
            {
                time += ((b + rate - 1)/rate);
            }
            return time <= h;
        };

        while(l <= r)
        {
            int m = (r-l)/2 + l;
            if(check(m)) r = m -1;
            else l = m + 1;
        }
        return l;
    }
};
