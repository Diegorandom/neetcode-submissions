class Solution {
public:
    int trap(vector<int>& height) {
        int left=0, right=height.size()-1, water = 0, maxL=0, maxR=0, minH=0,x, y;
        while(left<right){
            x=height[left];
            y=height[right];
            if(x<y){
                maxL = max(maxL, x);
                maxR = max(maxR, y);
                minH = min(maxL, maxR);
                if(minH > x){
                    water += (minH-x) > 0 ? minH-x : 0;
                }
                left++;
            } else {
                maxL = max(maxL, x);
                maxR = max(maxR, y);
                minH = min(maxL, maxR);
                if(minH > y){
                    water += (minH-y) > 0 ? minH-y : 0;
                }
                right--;
            }
        }
        return water;
    }
};
