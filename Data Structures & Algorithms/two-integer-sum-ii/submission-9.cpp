class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0,right=0,idx=0,idx2=numbers.size()-1;
        vector<int> output;;
        bool found = false;
        while(true){
            left=numbers[idx];
            right=numbers[idx2];
            if((left+right) < target){
                idx++;
            }else if((left+right) > target){
                idx2--;
            }else{
                found = true;
                break;
            }
        }
        output.push_back(idx+1);
        output.push_back(idx2+1);
        return output;
    }
};
