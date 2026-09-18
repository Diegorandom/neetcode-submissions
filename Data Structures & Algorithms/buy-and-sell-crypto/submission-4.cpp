class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lw=0, rw=0, gain=0;
        for(int i=0; i<prices.size(); i++){
            if(prices[lw] < prices[rw]){
                gain = max(gain, (prices[rw]-prices[lw]));
            }
            if(prices[rw] < prices[lw]){
                lw=rw;
            }
            rw +=1;
        }
        return gain;
    }
};
