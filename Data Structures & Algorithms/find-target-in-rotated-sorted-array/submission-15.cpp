class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lp=0, rp=nums.size()-1;
        while(lp<=rp){
            long long mid=lp+(rp-lp)/2;
            if(nums[mid] == target){
                return mid;
            }
            if(target > nums[mid] && nums[lp] < target && nums[rp] < nums[mid] 
            || nums[mid] > target && nums[lp] > target && nums[rp] < nums[mid]
            || target > nums[mid] && nums[lp] > target
            || nums[mid] >= nums[lp] && target > nums[mid]  ){
                lp = mid+1;
            } else {
                rp = mid-1;
            }
        }
        return -1;
    }
};
