class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(remove_if(s.begin(), s.end(), [](unsigned char c){return !isalnum(c);}), s.end());
        transform(s.begin(), s.end(), s.begin(), [](unsigned char ch){
            return static_cast<char>(tolower(ch));
        });
        cout << s;
        string p1, p2;
        if(s.length() == 0){
            return true;
        }
        for(int i=0; i<s.length(); i++){
            p1 = s[i];
            p2 = s[(s.length()-1)-i];
            cout << p1 + " " + p2;
            if(p1 != p2){
                return false;
            }
            if(i == (s.length()-1)/2){
                return true;
            }
        }
    }
};
