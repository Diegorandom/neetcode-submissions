class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lp=0, rp=nums.size()-1;
        int mid = (rp-lp)/2;
        while(rp>=lp){
            if(target<nums[mid]){
                rp=mid-1;
                mid = lp+((rp-lp)/2);
            } else if(target>nums[mid]){
                lp=mid+1;
                mid = lp+ ((rp-lp)/2);
            } else if(target == nums[mid]){
                return mid;
            }
        }
        return -1;
    }
};
