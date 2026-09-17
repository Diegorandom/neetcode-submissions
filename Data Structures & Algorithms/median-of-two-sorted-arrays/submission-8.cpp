class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() < nums1.size()){
            nums1.swap(nums2);
        }
        int total = nums1.size()+nums2.size();
        int half = (total+1)/2;
        int lp=0, rp=nums1.size();
        while(true){
            int i=(lp + rp)/2;
            int j = half-i;

            double aLeft = i>0 ?             nums1[i-1] : -numeric_limits<double>::infinity();
            double aRight = i<nums1.size() ? nums1[i] : numeric_limits<double>::infinity();
            double bLeft = j>0 ?             nums2[j-1] : -numeric_limits<double>::infinity();
            double bRight = j<nums2.size() ? nums2[j] : numeric_limits<double>::infinity();

            if(aLeft <= bRight && bLeft <= aRight){
                if(total % 2 != 0){
                    return max(aLeft, bLeft);
                }
                return (max(aLeft, bLeft) + min(aRight, bRight))/2.0;
            } else if(aLeft > bRight){
                rp = i-1;
            } else {
                lp = i+1;
            }
        }
    }
};
