class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // store dist + index in heap 
        // max heap -> push points if they are smaller -> keep size k
        priority_queue<pair<double, int>> heap;

        for(int i{}; i < points.size(); ++i) {
            auto& p = points[i];
            double score = sqrt(p[0]*p[0] + p[1]*p[1]);
            if(heap.size() < k || score < heap.top().first) heap.push({score, i});
            if(heap.size() > k) heap.pop();
        }
        vector<vector<int>> ans;
        while(!heap.empty()) {
            ans.push_back(points[heap.top().second]); heap.pop();
        }
        return ans;
    }
};
