class MinStack {
public:
    vector<int> st;
    vector<int> minV;
    MinStack() : st() {}
    
    void push(int val) {
        if(minV.empty()){
            minV.push_back(val);
        } else {
            minV.push_back(min(minV.back(), val));
        }
        st.push_back(val);
    }
    
    void pop() {
       st.pop_back();
       minV.pop_back();
    }
    
    int top() {
        return st[st.size()-1];
    }
    
    int getMin() {
        return minV.back();
    }
};
