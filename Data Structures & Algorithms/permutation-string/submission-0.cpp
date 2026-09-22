class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       if (s1.size() > s2.size())
        return false;

    std::array<int, 26> count1{};
    std::array<int, 26> count2{};

    // Frequency of characters in s1
    for (char c : s1)
        count1[c - 'a']++;

    // First window in s2
    for (int i = 0; i < s1.size(); ++i)
        count2[s2[i] - 'a']++;

    if (count1 == count2)
        return true;

    // Slide the window
    for (int i = s1.size(); i < s2.size(); ++i)
    {
        // Add new character
        count2[s2[i] - 'a']++;

        // Remove character leaving the window
        count2[s2[i - s1.size()] - 'a']--;

        if (count1 == count2)
            return true;
    }

    return false;
    }
};
