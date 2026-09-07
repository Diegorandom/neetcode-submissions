class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left=0, right=heights.size()-1, res=0;
        int i=heights[left],j=heights[right];
        while(left<right){
            int a = (right-left)*min(i, j);
            res = max(res,a);
            if(i<j){
                left++;
            } else {
                right--;
            }
            i=heights[left];
            j=heights[right];
        }
        return res;
    }
};
