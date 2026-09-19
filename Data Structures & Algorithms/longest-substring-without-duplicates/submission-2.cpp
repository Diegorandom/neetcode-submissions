class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen;
        int longest = 0;
        int l = 0;

        for (int r = 0; r < s.length(); ++r) {
            char c = s[r];

            // Only move l forward if this character is inside
            // the current window.
            if (lastSeen.count(c) && lastSeen[c] >= l) {
                l = lastSeen[c] + 1;
            }

            lastSeen[c] = r;
            longest = max(longest, r - l + 1);
        }

        return longest;
    }
};