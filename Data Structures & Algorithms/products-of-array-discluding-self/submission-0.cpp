class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> o;
        int prefix = 0, posfix = 0;
        for(int i=0; i<nums.size(); i++){
            if(i==0){
                o.push_back(1);
                prefix = nums[i];
                continue;
            }
            o.push_back(prefix);
            prefix *= nums[i];
        }

        for(int i=nums.size()-1; i>-1; i--){
            if(i==nums.size()-1){
                o[i] *= 1;
                posfix = nums[i];
                continue;
            }
            o[i] *= posfix;
            posfix *= nums[i];
        }

        return o;
    }
};