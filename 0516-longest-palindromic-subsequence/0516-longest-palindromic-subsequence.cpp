class Solution {
public:
    int findLongestPal(const string& s, int i, int j, vector<vector<int>>& t) {
        if (i > j) {
            return 0;
        }

        if (i == j) {
            return 1;
        }

        if (t[i][j] != -1) {
            return t[i][j];
        }

        if (s[i] == s[j]) {
            return t[i][j] = 2 + findLongestPal(s, i + 1, j - 1, t);
        }

        return t[i][j] = max(findLongestPal(s, i + 1, j, t),
                             findLongestPal(s, i, j - 1, t));
    }
    int longestPalindromeSubseq(string s) {
        int n      = s.length();
        int maxLen = 0;
        string r   = string(rbegin(s), rend(s));

        vector<vector<int>> t(n+1, vector<int>(n+1, 0));
        
        for(int i=1; i<n+1; i++) {

            for(int j=1; j<n+1; j++) {

                if(s[i-1] == r[j-1]) {
                    t[i][j] = 1 + t[i-1][j-1];
                } else {
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }
        
        return t[n][n];
        
        // vector<vector<int>> t(n, vector<int>(n, -1));
        // return findLongestPal(s, 0, n - 1, t);
    }
};