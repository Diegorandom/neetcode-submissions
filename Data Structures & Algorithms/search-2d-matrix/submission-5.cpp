class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lp=0, up=0, bp=matrix.size()-1, rp=matrix[up].size()-1;
        pair<int, int> mid={ (bp-up)/2, (rp-lp)/2 };
        while(rp>=lp && bp >= up){
            if(target<matrix[mid.first][mid.second]){
                if(target<matrix[mid.first][0]){
                    bp=mid.first-1;
                    mid.first=up+((bp-up)/2);
                } else if(target<matrix[mid.first][mid.second]){ 
                    rp=mid.second-1;
                    mid.second=lp+((rp-lp)/2);
                }
            } else if(target>matrix[mid.first][mid.second]){
                if(target>matrix[mid.first][matrix[mid.first].size()-1]){
                    up=mid.first+1;
                    mid.first=up+((bp-up)/2);
                } else if(target>matrix[mid.first][mid.second]){ 
                    lp=mid.second+1;
                    mid.second=lp+((rp-lp)/2);
                }
            } else if(target == matrix[mid.first][mid.second] ){
                return true;
            }
        }
        return false;
    }
};
