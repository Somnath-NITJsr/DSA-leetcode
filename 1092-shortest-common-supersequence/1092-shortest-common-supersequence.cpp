class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();

        vector<vector<int>> t(m+1, vector<int>(n+1, 0));

        // for the row
        for(int row=0; row<m+1; row++) {
            t[row][0] = 0;
        }

        // for the col
        for(int col=0; col<n+1; col++) {
            t[0][col] = 0;
        }

        // build the table

        for(int i=1; i<m+1; i++) {

            for(int j=1; j<n+1; j++) {

                if(s1[i-1] == s2[j-1]) {
                    t[i][j] = 1 + t[i-1][j-1];
                } else {
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }

        string ans = "";

        int i = m, j = n;

        while(i > 0 && j > 0) {

            if(s1[i-1] == s2[j-1]) {
                ans.push_back(s1[i-1]);
                i--;
                j--;
            } else if(t[i-1][j] > t[i][j-1]) {
                ans.push_back(s1[i-1]);
                i--;
            } else {
                ans.push_back(s2[j-1]);
                j--;
            }
        }

        while (i > 0) {
            ans.push_back(s1[i - 1]);
            i--;
        }
        while (j > 0) {
            ans.push_back(s2[j - 1]);
            j--;
        }

        reverse(begin(ans), end(ans));
        return ans;
    }
};