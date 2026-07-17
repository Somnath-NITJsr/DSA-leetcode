class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        stringstream ss(s);
        string token;

        int countWords = 0;
        vector<string> words;
        // tokenizing
        while(getline(ss, token, ' ')) {
            words.push_back(token);
            countWords++;
        }

        int n = pattern.length();
        if(n != countWords) {
            return false;
        }

        unordered_map<string, char> mp;
        set<char> used;

        for(int i=0; i<n; i++) {

            string word = words[i];
            char ch     = pattern[i];

            if(mp.find(word) == mp.end() && used.find(ch) == used.end()) {
                used.insert(ch); 
                mp[word] = ch; // mapped
            } else if(pattern[i] != mp[word]) { // it means that same pattern 'a' is now getting mapped to different word, so false
                return false;
            }
        }
        return true;
    }
};