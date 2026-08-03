class Solution {
public:
    bool checkPal(const string& s, int i, int j, vector<vector<int>>& t) {
        if(i > j) {
            return true;
        }

        if(t[i][j] != -1) {
            return t[i][j]; // -1 _ not solved, 0 _ false, 1 _ true
        }

        if(s[i] == s[j]) {

            return checkPal(s, i+1, j-1, t);
        }

        return false;
    }
    int countSubstrings(string s) {
        int n = s.length();

        vector<vector<bool>> t(n, vector<bool>(n, false));

        int count = 0;

        for(int L=1; L<=n; L++) {

            for(int i=0; i+L-1<n; i++) {

                int j = i+L-1;

                if(i == j) {
                    t[i][i] = true;
                } else if(i+1 == j) {
                    t[i][j] = (s[i] == s[j]);
                } else {
                    t[i][j] = (s[i] == s[j] && t[i+1][j-1]); // if both are true, then true
                }

                if(t[i][j] == true) {
                    count++;
                }
            }
        }

        return count;

        // int count = 0;
        // vector<vector<int>> t(n+1, vector<int>(n+1, -1));

        // for(int i=0; i<n; i++) {

        //     for(int j=i; j<n; j++) {

        //         if(checkPal(s, i, j, t)) {
        //             count++;
        //         }
        //     }
        // }

        // return count;
    }
};