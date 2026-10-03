class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // run algo on the smaller array
        if(nums2.size() < nums1.size()) return findMedianSortedArrays(nums2, nums1);

        int n = nums1.size(), m = nums2.size();
        int target = (n+m)/2;
        bool is_odd = (n+m)%2;

        // binary search on the smaller arr
        int l = 0, r = n;
        while(l <= r) {
            int mid = (r-l)/2 + l;
            int needed  = target - mid;
            int smallL = (mid > 0) ? nums1[mid-1] : INT_MIN;
            int largeL = (needed > 0) ? nums2[needed-1] : INT_MIN;
            int smallR = (mid < n) ? nums1[mid] : INT_MAX;
            int largeR = (needed < m) ? nums2[needed] : INT_MAX;
            // check if partition is correct
            if(smallL <= largeR && largeL <= smallR) {
                if(is_odd) return (double)min(largeR, smallR);
                else return (max(smallL, largeL)+ min(smallR, largeR))/2.0;
            }
            else if(largeL > smallR) l = mid + 1;
            else r = mid-1;
        }
        return 0.0;
        
    }
};
