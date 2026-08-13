class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;


        /*
            two maps for inter-mapping of each character from s, t
            characters of s to characters of t and vice-versa.
        */


        int n = s.length();

        for(int i=0; i<n; i++) {

            char ch1 = s[i];
            char ch2 = t[i];

            if(mp1.find(ch1) != mp1.end() && mp1[ch1] != ch2 ||
               mp2.find(ch2) != mp2.end() && mp2[ch2] != ch1) {
                return false;
            }

            mp1[ch1] = ch2;
            mp2[ch2] = ch1;

        }

        return true;
    }
};