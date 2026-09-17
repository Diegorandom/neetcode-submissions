class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> store;
    TimeMap() {
        store.clear();
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        string res = "";
        vector<pair<string, int>>& values = store[key];
        //sort(values.begin(), values.end());
        int lp=0, rp=values.size()-1;
        while(lp<=rp){
            int mid = lp + (rp-lp)/2;
            if(values[mid].second <= timestamp){
                lp = mid+1;
                res=values[mid].first;
            } else if(values[mid].second > timestamp){
                rp = mid-1;
            }
        }
        return res;
    }
};
