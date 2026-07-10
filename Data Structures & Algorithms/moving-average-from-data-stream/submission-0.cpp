class MovingAverage {

int idx;
int count;
vector<int> arr;
int _size; 
double sum;
public:
    MovingAverage(int size) :  idx(0), count(0), _size(size), sum(0.0) {
        arr.resize(size, 0.0);
    }
    
    double next(int val) {
        sum -= arr[idx]; 
        arr[idx] = val;
        sum += val;
        idx = (idx+1)%_size;
        count++;

        return sum / (double) min(count, _size);
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
