class MinStack {
public:
    vector<int> st;

    MinStack() : st() {
        
    }
    
    void push(int val) {
        st.push_back(val);
    }
    
    void pop() {
       st.pop_back();
    }
    
    int top() {
        return st[st.size()-1];
    }
    
    int getMin() {
        int minV=numeric_limits<int>::max();
        for(int i=0; i<st.size(); i++){
            minV=min(minV, st[i]);
        }
        return minV;
    }
};
