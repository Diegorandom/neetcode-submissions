class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map1 = {};
        for(int i=0; i<s.length(); i++){
            map1.contains(s[i]) ? map1.insert({s[i], map1[s[i]]++}) : map1.insert({s[i], 1});
        }

        for(int i=0; i<t.length(); i++){
            map1.contains(t[i]) ? map1.insert({t[i], map1[t[i]]--}) : map1.insert({t[i], -1});
        }

        for(auto it = map1.begin(); it != map1.end(); it++){
            if(it->second != 0){
                return false;
            }
        }
        return true;
    }
};
