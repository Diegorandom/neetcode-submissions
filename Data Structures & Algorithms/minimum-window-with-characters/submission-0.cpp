class Solution {
public:
    string minWindow(string s, string t) {
        // optimar approach -> sliding window + character frequency maps.
        if(t.length() == 0) { return ""; }

        int sMap[128] = {0};
        int tMap[128] = {0};
        for(const char &c : t){tMap[c]++;}

        int left=0;
        int right=0;
        int res=-1;
        int resLen = INT_MAX;
        int current = 0;
        int target = 0;
        for(const int &val : tMap){
            if(val > 0) { target++; }
        }

        while(right < s.length()){
            sMap[s[right]]++;
            if(tMap[s[right]] != 0 && tMap[s[right]] == sMap[s[right]]){ current++;}

            while(current == target){
                if(right-left+1 < resLen){
                    res=left;
                    resLen=right-left+1;
                }
                sMap[s[left]]--;
                if(tMap[s[left]] != 0 && tMap[s[left]] > sMap[s[left]]){ current--;}
                left++;
            }
            
            right++;
        }

        if(resLen == INT_MAX){
            return "";
        }

        string str = s.substr(res, resLen);
        return str;
    }
};
