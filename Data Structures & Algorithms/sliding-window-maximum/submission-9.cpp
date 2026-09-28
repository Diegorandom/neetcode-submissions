class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int windowSize=k;
        vector<int> output;

        for(int i=0; i<nums.size(); i++){
            if(dq.empty()){
                dq.push_back(i);
            }else{
                if(dq.front() < ((i-k+1) > 0 ? (i-k+1) : 0 )){
                    dq.pop_front();
                }
                while(!dq.empty() && nums[dq.back()] < nums[i]){
                    dq.pop_back();
                }
                dq.push_back(i);
            }
            --windowSize;
            if(windowSize == 0){
                output.push_back(nums[dq.front()]);
                windowSize=1;
            }
        }
        return output;
    }
};
