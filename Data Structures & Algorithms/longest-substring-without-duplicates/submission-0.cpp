class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest=0, l=0, r=0;
        for(int i=0; i<s.length(); i++){
            if(r < s.length()){
                for(int j=r-1; j>=l; j--){
                    if(s[r] == s[j]){
                        l=j+1;
                    }
                }
            }
            longest=max((r-l)+1, longest);
            r++;
        }
        return longest;
    }
};
