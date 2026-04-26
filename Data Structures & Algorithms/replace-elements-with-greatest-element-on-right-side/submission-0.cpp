class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int running_max = arr.back();
        int size = arr.size();
        arr[size - 1] = -1;
        for(int i=size-2; i>=0; --i)
        {
            int x = arr[i];
            arr[i] = running_max;
            running_max = max(x, arr[i]);
        }
        return arr;
    }
};