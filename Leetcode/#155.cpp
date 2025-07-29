class MinStack {
public:    
    stack<pair<int, int>> temp; 

    MinStack() {
        
    }
    
    void push(int val) {
        if(temp.empty()) {
            temp.push({val, val});
        } else {
            temp.push({val, min(val, temp.top().second)});
        }
    }
    
    void pop() {
        temp.pop();
    }
    
    int top() {
        return temp.top().first;
    }
    
    int getMin() {
        return temp.top().second;
    }
};

class MinStack {
public:
    long long min = LLONG_MAX;
    stack<long long> temp; 

    MinStack() {
        
    }
    
    void push(int val) {
        if(temp.empty()) {
            min = val;
            temp.push(val);
            return;
        }

        if(val >= min) {
            temp.push(val);
        } else {
            temp.push((2LL * val - min));
            min = val;
        }
    }
    
    void pop() {
        long long top = temp.top();
        
        if(top >= min) {
            temp.pop();
        } else if(top < min){
            long long newMin = 2LL * min - top;
            min = newMin;
            temp.pop();
        }
    }
    
    int top() {
        long long top = temp.top();
        if(top < min) {
            top = min;
        }
        return top;
    }
    
    int getMin() {
        return min;
    }
};
//TC - O(1) - for all custom stack operations
//SC - O(n) - We only use one stack

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */