class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();

        sort(begin(s), end(s));
        sort(begin(t), end(t));

        return s == t;


        // if(m != n) {
        //     return false;
        // }

        // string temp = s + t;

        // for(int i=0; i<n; i++) {

        //     string check = temp.substr(i, n);

        //     if(check == t) {
        //         return true;
        //     }
        // }

        // return false;
    }
};