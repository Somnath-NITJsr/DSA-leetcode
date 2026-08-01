class Solution {
public:
    int findLCS(const string& text1, const string& text2, int i, int j, int& m, int& n, vector<vector<int>>& t) {
        if(i == m || j == n) {
            return 0;
        }

        if(t[i][j] != -1) {
            return t[i][j];
        }

        if(text1[i] == text2[j]) {
            return 1 + findLCS(text1, text2, i+1, j+1, m, n, t);
        }

        int skip1 = findLCS(text1, text2, i, j+1, m, n, t);
        int skip2 = findLCS(text1, text2, i+1, j, m, n, t);

        return t[i][j] = max(skip1, skip2);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();


        vector<vector<int>> t(m+1, vector<int>(n+1, 0));

        // for the row
        for(int row=0; row<m+1; row++) {
            t[row][0] = 0;
        }

        // for the col
        for(int col=0; col<n+1; col++) {
            t[0][col] = 0;
        }

        for(int i=1; i<m+1; i++) {

            for(int j=1; j<n+1; j++) {

                if(text1[i-1] == text2[j-1]) {
                    t[i][j] = 1 + t[i-1][j-1];
                } else {
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }

        return t[m][n];

        // vector<vector<int>> t(m+1, vector<int>(n+1, -1));

        // return findLCS(text1, text2, 0, 0, m, n, t);
    }
};