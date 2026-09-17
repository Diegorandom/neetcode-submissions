class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
        int lp = 0, rp=nums1.size()-1;
        double mid=lp+(rp-lp)/2;
        double res = 0;
        if(nums1.size()%2 == 0){
            res = (nums1[mid] + nums1[mid+1])/2.0;
        } else {
            res=nums1[mid];
        }
        return res;
    }
};
