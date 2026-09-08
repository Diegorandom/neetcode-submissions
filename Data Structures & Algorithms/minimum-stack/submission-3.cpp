class MinStack {
public:
    stack<int> st;

    MinStack() : st() {
        
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
        stack<int> temp(st);
        int minV =numeric_limits<int>::max();
        while(!temp.empty()){
            minV = min(minV, temp.top());
            temp.pop();
        }
        return minV;
    }
};
