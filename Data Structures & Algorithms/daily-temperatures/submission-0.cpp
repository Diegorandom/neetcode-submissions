class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<tuple<int, int>> st;
        vector<int> output(temperatures.size(),0); //temp,idx
        for(int i=0; i<(int)temperatures.size(); i++){
            while(!st.empty() && temperatures[i] > get<0>(st.top())){
                int prevIdx=get<1>(st.top());
                st.pop();
                output[prevIdx] = (i-prevIdx);
            }
            st.push(make_tuple(temperatures[i], i));
        }
        return output;
    }
};
