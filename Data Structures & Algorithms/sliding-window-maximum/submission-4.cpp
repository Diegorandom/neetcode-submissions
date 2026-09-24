class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> output;
        deque<int> d;
        int l=0, r=0;

        while(r < nums.size()){
            while(!d.empty() && nums[d.front()] < nums[r]){
                d.pop_front();
            }
            d.push_front(r);
            if(d.back() < l){ d.pop_back(); }
            if(r+1 >= k){
                output.push_back(nums[d.back()]);
                l++;
            }
            r++;
        }
        return output;
    }
};
