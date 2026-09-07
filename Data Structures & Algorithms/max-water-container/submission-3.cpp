class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left=0, right=heights.size()-1, max=0;
        auto max_it = max_element(heights.begin(), heights.end());
        int max_value = *max_it;
        int i=heights[left],j=heights[right];
        while(left<right){
            int a = (right-left)*min(i, j);
            if(max < a){
                max = a;
            }
            if(i<max_value && i<j){
                left++;
            } else if(j<max_value){
                right--;
            } else {
                break;
            }
            i=heights[left];
            j=heights[right];
        }
        return max;
    }
};
