class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // input
        std::vector<std::vector<string>> output {};
        std::map<string, int> ref;
        /* Algorithm
            1. iterate over the strs vector
            2. each string will be saved into a vector for its own anagrams
                2.a the first string gets saved directly
            3. After the first string, all other strings will get checked to see 
            if there's already a vector for its anagrams
                3.a if so store in the appropiate vector
            4. if there's no matching anagram vector store in a new vector
        */
        for(int i=0; i<strs.size(); i++){
            string temp_s = strs[i];
            sort(temp_s.begin(), temp_s.end());
            auto it = ref.find(temp_s);

            if(it != ref.end()){
                output[it->second].push_back(strs[i]);
            } else {
                vector<string> temp_v {strs[i]};
                output.push_back(temp_v);
                string temp_s = strs[i];
                sort(temp_s.begin(), temp_s.end());
                ref.insert({temp_s, output.size()-1});
            }

        }

        // output
        // vector of vectors with the anagrams grouped
        return output;
    }
};
