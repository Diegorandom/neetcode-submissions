class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> set = {};

        for(int i=0; i<nums.size(); i++){
            auto it = set.find(nums[i]);
            if(it == set.end()){
                set.insert(nums[i]);
            }else{
                return true;
            }
        }
        return false;
    }
};