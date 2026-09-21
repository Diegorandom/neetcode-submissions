class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int maxFreq = 0;
        int l = 0;
        int res = 0;

        for (int r = 0; r < s.length(); ++r) {
            count[s[r] - 'A']++;
            maxFreq = max(maxFreq, count[s[r] - 'A']);

            // If the window size minus the most frequent char count
            // exceeds k, shrink from the left.
            while ((r - l + 1) - maxFreq > k) {
                count[s[l] - 'A']--;
                l++;
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};