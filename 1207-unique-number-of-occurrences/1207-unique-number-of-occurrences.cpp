class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        unordered_map<int, int> mpp;

        for(auto& it: arr) {
            mpp[it]++;
        }

        unordered_set<int> freq;
        for(auto& it: mpp) {
            int occ = it.second;

            if(freq.find(occ) != freq.end()) {
                return false;
            }
            freq.insert(occ);
        }
        return true;
        
        
        // Asked by Google
        // vector<int> vec(2001, 0);

        // for(auto& it: arr) {
        //     vec[it + 1000]++;
        // }

        // sort(begin(vec), end(vec));

        // for(int i=1; i<2001; i++) {
        //     if(vec[i] != 0 && vec[i] == vec[i-1]) {
        //         return false;
        //     }
        // }

        // return true;
    }
};