class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), [](unsigned char ch){
            return isupper(ch) ? static_cast<char>(tolower(ch)) : ch;
        });
        char p1, p2;
        if(s.length() == 0){
            return true;
        }
        int i=0, j=s.length()-1;
        while(true){
            p1 = s[i];
            while(i<j && !((p1 >= '0' && p1 <='9') || (p1>='a' && p1 <='z'))){
                i++;
                p1 = s[i];
            }
            p2 = s[j];
            while(j>i && !((p2 >= '0' && p2 <='9') || (p2>='a' && p2 <='z'))){
                j--;
                p2 = s[j];
            }
            cout << string() + p1 + " " + string() + p2;
            if(p1 != p2){
                return false;
            }
            if(i >= j){
                return true;
            }
            i++;
            j--;
        }
    }
};
