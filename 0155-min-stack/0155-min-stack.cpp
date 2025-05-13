class MinStack {
private:
    stack<int> data;
    stack<int> mins;
public:
    MinStack() { } // constructor;
    
    void push(int val) {
        data.push(val);
        if(mins.empty() || val <= mins.top()){
            mins.push(val);
        }
        // else {
        //     mins.push(mins.top());
        // }
    }
    
    void pop() {
        if(data.top() == mins.top()) mins.pop();
        data.pop();
    //    mins.pop(); 
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return mins.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */