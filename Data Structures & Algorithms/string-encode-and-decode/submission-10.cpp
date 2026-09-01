class Solution {
public:
    string encode(vector<string>& strs) {
        string r;
        for(int i = 0; i < strs.size(); i++){
            r += to_string(strs[i].length()) + "#" + strs[i];
        }
        return r;
    }

    vector<string> decode(string s) {
        vector<string> r;
        int i = 0;
        
        while(i < s.length()){
            // Parse the length
            int wordLength = 0;
            while(i < s.length() && isdigit(s[i])){
                wordLength = wordLength * 10 + (s[i] - '0');
                i++;
            }
            
            // Skip the '#'
            i++;
            
            // Use substr ONLY once at the end
            r.push_back(s.substr(i, wordLength));
            i += wordLength;
        }
        
        return r;
    }
};