class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> list;
        vector<vector<int>> o;
        int i,j,k,sum;
        for(int x=0; x<nums.size(); x++){
            i=nums[x];
            if(x!=0 && i == nums[x-1]){
                continue;
            }
            int left=x+1, right=nums.size()-1;
            while(left<right){
                j=nums[left];
                k=nums[right];
                sum = i+j+k;
                if(sum>0){
                    right--;
                } else if(sum<0){
                    left++;
                } else {
                    list.push_back(i);
                    list.push_back(j);
                    list.push_back(k);
                    o.push_back(list);
                    list.clear();
                    left++;
                    while(nums[left] == nums[left-1] && left<right){
                        left++;
                    }
                }
            }
        }
        return o;
    }
};
