class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> mheap;
    int size;
    KthLargest(int k, vector<int>& nums) {
        // min heap tracks the top k largest elements
        for(int i : nums) {
            mheap.push(i); 
            if(mheap.size() > k) mheap.pop();
        }
        size = k;
    }
    
    int add(int val) {
        mheap.push(val);
        if(mheap.size() > size) mheap.pop();
        return mheap.top();
    }
};
