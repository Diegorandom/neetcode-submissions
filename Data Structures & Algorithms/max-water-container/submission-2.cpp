class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left=0, right=heights.size()-1;
        vector<int> areas;
        auto max_it = max_element(heights.begin(), heights.end());
        int max_value = *max_it;
        int i=heights[left],j=heights[right];
        while(left<right){
            int a = (right-left)*min(i, j);
            areas.push_back(a);
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
        auto max_area_it = max_element(areas.begin(), areas.end());
        return *max_area_it;
    }
};
