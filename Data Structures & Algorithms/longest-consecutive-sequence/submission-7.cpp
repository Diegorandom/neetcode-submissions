class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        s.insert(nums.begin(), nums.end());
        int longest =0;
        for(int i=0; i<nums.size(); i++){
           auto it = s.find(nums[i]-1);
           if(it == s.end()){
                int length = 0;
                while(true){
                    auto it2=s.find(nums[i]+length); 
                    if(it2 == s.end()){
                        break;
                    }
                    length +=1;
                }
                longest = max(length, longest);
           }
        }
        return longest;
    }
};
