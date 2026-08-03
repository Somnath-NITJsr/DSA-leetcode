class Solution {
public:
    int solve(const string& s1, const string& s2, int m, int n, vector<vector<int>>& t) {
        if (m == 0 || n == 0) {
            return m + n;
        }
        
        if(t[m][n] != -1) {
            return t[m][n];
        }

        if(s1[m-1] == s2[n-1]) {
            return solve(s1, s2, m-1, n-1, t);
        }

        int insert  = 1 + solve(s1, s2, m-1, n, t);
        int delete_ = 1 + solve(s1, s2, m, n-1, t);
        int replace = 1 + solve(s1, s2, m-1 , n-1, t);


        return t[m][n] = min({insert, delete_, replace});
    }
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<vector<int>> t(m+1, vector<int>(n+1, -1));

        return solve(word1, word2, m, n, t);
    }
};