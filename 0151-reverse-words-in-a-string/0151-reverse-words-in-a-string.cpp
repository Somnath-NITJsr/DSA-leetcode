class Solution {
public:
    string reverseWords(string s) {
        
        int n = s.length();

        // 1. reverse the string
        reverse(begin(s), end(s));

        // 2. l, r, i

        int l = 0;
        int r = 0;
        int i = 0;

        while(i < n) {

            while(i < n && s[i] != ' ') {
                s[r++] = s[i++];
            }


            // reverse
            if(l < r) {
                reverse(s.begin() + l, s.begin() + r);
                s[r] = ' ';
                r++;
                l    = r;
            }
            i++;
        }

        return s.substr(0, r-1);

        /*
            // tokeniser
        stringstream ss(s);

        string token  = "";
        string result = "";

        while(ss >> token) {

            result = token + " " + result;
        }
        int n = result.size();

        return result.substr(0, n-1);

        */
    }
};