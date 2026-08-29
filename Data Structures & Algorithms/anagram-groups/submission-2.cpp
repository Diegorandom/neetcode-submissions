class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups {};
        vector<vector<string>> output;

        for(string& str : strs){
            string sorted = str;
            sort(sorted.begin(), sorted.end());
            groups[sorted].push_back(str);
        }

        for(auto& group : groups){
            output.push_back(std::move(group.second));
        }
        return output;
    }
};
