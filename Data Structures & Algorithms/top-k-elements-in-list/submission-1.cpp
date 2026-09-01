class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> m;
        vector<vector<int>> buckets(n+1);
        vector<int> r;

        for(int key : nums){
            m[key]++;
        }

        for(const auto& [key, value] : m){
            buckets[value].push_back(key);
        }

        for(int i=n; i>0; i--){
            for(int n : buckets[i]){
                r.push_back(n);
                if(r.size() == k){
                    break;
                }
            }
            if(r.size() == k){
                break;
            }
        }

        return r;
    }
};
