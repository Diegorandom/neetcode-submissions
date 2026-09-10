class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double> st;
        vector<pair<int,int>> pairs;
        pairs.reserve(position.size());
        for(int i=0; i<position.size(); i++){
            pairs.emplace_back(position[i],speed[i]);
        }
        sort(pairs.rbegin(),pairs.rend());
        for(int i=0; i<pairs.size(); i++){
            double arrivalTime = (double)(target-pairs[i].first)/pairs[i].second;
            if(st.empty() || arrivalTime > st.top()){
                st.push(arrivalTime);
            }
        }
        return st.size();
    }
};
