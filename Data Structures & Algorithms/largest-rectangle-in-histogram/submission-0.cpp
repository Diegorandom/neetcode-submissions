class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxA = 0;
        stack<pair<int,int>> st;
        for(int i=0; i<(int)heights.size(); i++){
            int index=i;
            while(!st.empty() && heights[i] <= st.top().second){
                int lastHeight = st.top().second;
                int leftBound = st.top().first;
                st.pop();
                int rightBound = i;
                int lastWidth = rightBound - leftBound;
                maxA = max(maxA, (lastHeight*lastWidth));
                index = leftBound;
            }
            st.push({index, heights[i]});
        }

        while(!st.empty()){
            int width = heights.size() - st.top().first;
            int height = st.top().second;
            st.pop();
            maxA = max(maxA, (height*width));
        }

        return maxA;
    }
};
