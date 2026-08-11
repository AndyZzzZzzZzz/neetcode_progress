class MedianFinder {
public:
    // use min heap to greater end and max heap to track lower end
        priority_queue<int> max_heap;
        priority_queue<int, vector<int>, greater<int>> min_heap;
    MedianFinder() {
        
        


    }
    
    void addNum(int num) {
        
        max_heap.push(num);
        min_heap.push(max_heap.top());
        max_heap.pop();
        if(min_heap.size() > max_heap.size()) {
            max_heap.push(min_heap.top()); 
            min_heap.pop();
        } 
    }
    
    double findMedian() {
        if(min_heap.empty() && max_heap.empty()) return 0.0;
        if(max_heap.size() > min_heap.size()) return (double)max_heap.top();
        return ((double)max_heap.top() + min_heap.top()) / 2.0;
    }
};
