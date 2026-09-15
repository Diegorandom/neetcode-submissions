class Solution {
public:
    int findMin(vector<int> &nums) {
        int lp=0, rp=nums.size()-1;
        long long mid;
        int minV = nums[lp];
        while(lp<=rp){
            if(nums[lp] < nums[rp]){
                minV = min(minV, nums[lp]);
                break;
            }
            mid=lp+(rp-lp)/2;
            minV = min(minV, nums[mid]);
            if(nums[mid] >= nums[lp]){
                lp = mid+1;
            } else {
                rp = mid-1;
            }
        }
        return minV;
    }
};
