class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int localMax = 0, prefix = 0, tMax=0;
        for(int i=0; i<nums.size(); i++){
            if(i==0){
                prefix = nums[i];
                localMax = 1;
                tMax = max(localMax, tMax);
            }
            if((nums[i] - prefix) == 1){
                localMax += 1;
                prefix = nums[i];
                tMax = max(localMax, tMax);
            }if((nums[i] - prefix) != 0) {
                prefix = nums[i];
                tMax = max(localMax, tMax);
                localMax=1;
            }
        }
        return tMax;
    }
};
