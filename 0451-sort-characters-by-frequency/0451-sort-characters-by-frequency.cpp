class Solution {
public:
    string frequencySort(string s) {
        
        vector<pair<char, int>> vec(123, {0, 0});

        for(auto& ch: s) {

            int freq = vec[ch].second;
            vec[ch]  = {ch, freq+1};
        }


        auto lambda = [&](pair<char, int> p1, pair<char, int>p2) {
            return p1.second > p2.second;
        };
        
        sort(begin(vec), end(vec), lambda);

        string ans = "";
        for(auto& it: vec) {
            
            char ch   = it.first;
            int freq  = it.second;

            string temp = string(freq, ch);
            ans        += temp;
           
        }

        return ans;

    }
};