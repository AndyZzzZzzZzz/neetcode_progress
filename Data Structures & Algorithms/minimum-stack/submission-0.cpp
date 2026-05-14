class MinStack {
public:
    // two stack:
    // one track all elements
    // one track decreasing min elements
        stack<int> stk;
        stack<int> _min;
    MinStack() {
    
    }
    
    void push(int val) {
        stk.push(val);
        if(_min.empty() || val <= _min.top()) _min.push(val);
    }
    
    void pop() {
        if(stk.top() == _min.top()) _min.pop();
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return _min.top();
    }
};
