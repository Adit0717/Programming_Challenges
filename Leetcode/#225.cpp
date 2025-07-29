class MyStack {
public:
    queue<int> temp1;
    
    MyStack() {

    }
    
    void push(int x) {
        temp1.push(x);
        int temp = temp1.size();

        for(int i = 0; i < temp - 1; i++) {
            temp1.push(temp1.front());
            temp1.pop();
        }
    }
    //O(n) - worst case where you need to transfer n - 1 elements
    
    int pop() {
        int x = temp1.front();
        temp1.pop();
        
        return x;
    }
    //O(1)
    
    int top() {
        return temp1.front();        
    }
    //O(1)
    
    bool empty() {
        return temp1.empty();
    }
    //O(1)
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */