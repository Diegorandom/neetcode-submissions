class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) { return false; }

        int s1Map[26] = {0};
        int s2Map[26] = {0};
        int matches = 0;
        for(int i=0; i<s1.length(); i++){
            s1Map[s1[i] - 'a']++;
            s2Map[s2[i] - 'a']++;
        }

        for(int i=0; i<26; i++){
            if(s1Map[i] == s2Map[i]){ matches++; }\
        }

        int left=0;
        int right =s1.length();
        while(right < s2.length()){
            if(matches == 26){ return true; }

            int key=s2[right] - 'a';
            s2Map[key]++;
            if(s1Map[key] == s2Map[key]){ matches++; }
            else if(s1Map[key]+1 == s2Map[key]) { matches--; }

            key=s2[left]-'a';
            s2Map[key]--;
            if(s1Map[key] == s2Map[key]){matches ++;}
            else if(s1Map[key]-1 == s2Map[key]){ matches--;}

            left++;
            right++;
        }
        return matches == 26 ? true : false;
    }
};
