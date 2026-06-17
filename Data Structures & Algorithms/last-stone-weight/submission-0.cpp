class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> heap(stones.begin(), stones.end());
        while(heap.size() > 1) {
            int x = heap.top(); heap.pop();
            int y = heap.top(); heap.pop();
            heap.push(abs(x-y));
        }
        return heap.top();
    }
};
