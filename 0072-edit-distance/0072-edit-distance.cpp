class Solution {
public:
    int solve(const string& s1, const string& s2, int i, int j, int& m, int& n, vector<vector<int>>& t) {
        if (i == m) {
            return n - j;
        }
        if (j == n) {
            return m - i;
        }
        
        if(t[i][j] != -1) {
            return t[i][j];
        }

        if(s1[i] == s2[j]) {
            return solve(s1, s2, i+1, j+1, m, n, t);
        }

        int insert  = 1 + solve(s1, s2, i+1, j, m, n, t);
        int delete_ = 1 + solve(s1, s2, i, j+1, m, n, t);
        int replace = 1 + solve(s1, s2, i+1, j+1, m , n, t);


        return t[i][j] = min({insert, delete_, replace});
    }
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<vector<int>> t(m+1, vector<int>(n+1, -1));

        return solve(word1, word2, 0, 0, m, n, t);
    }
};