class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> complements = {};
        vector<int> response = {};

        for(int i=0; i<nums.size(); i++){
            if(i==0){
                complements.insert({nums[i],i});
                continue;
            }

            int complement = target - nums[i];
            auto it = complements.find(complement);
            if(it != complements.end()){
                cout<<it->first;
                response.push_back(it->second);
                response.push_back(i);
                return response;
            }

            complements.insert({nums[i],i});

        }   
    }
};
