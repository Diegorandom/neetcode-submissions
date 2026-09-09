class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        set<string> operands = {"+", "*", "-", "/"};
        for(int i=0; i<tokens.size(); i++){
            auto it = operands.find(tokens[i]);
            if(it == operands.end()){
                st.push(stoi(tokens[i]));
            } else {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                if(tokens[i] == "+"){
                    int res = num1 + num2;
                    st.push(res);
                }
                if(tokens[i] == "-"){
                    int res = num2-num1;
                    st.push(res);
                }
                if(tokens[i] == "/"){
                    int res = num2/num1;
                    st.push(res);
                }
                if(tokens[i] == "*"){
                    int res = num2*num1;
                    st.push(res);
                }
            }
        }
        return st.top();
    }
};
