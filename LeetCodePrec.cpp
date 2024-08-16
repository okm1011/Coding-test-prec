class MinStack {
public:
    stack<int>st;
    MinStack() {
        ;
    }
    
    void push(int val) {
        st.push(val);
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        stack<int>temp = st;
        int min = INT_MAX;
        while(!temp.empty()){
            if(temp.top()<min)min = temp.top();
            temp.pop();
        }
        return min;

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