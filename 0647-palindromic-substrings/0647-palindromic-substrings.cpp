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


        int count = 0;
        vector<vector<int>> t(n+1, vector<int>(n+1, -1));

        for(int i=0; i<n; i++) {

            for(int j=i; j<n; j++) {

                if(checkPal(s, i, j, t)) {
                    count++;
                }
            }
        }

        return count;
    }
};