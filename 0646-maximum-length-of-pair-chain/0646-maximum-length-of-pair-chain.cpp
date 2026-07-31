class Solution {
public:
    int solve(vector<vector<int>>& pairs, int i, int p, int& n, vector<vector<int>>& t) {

        if(i >= n) {
            return 0;
        }

        if(p != -1 && t[i][p] != -1) {
            return t[i][p];
        }

        // if take 
        int take = 0;

        if(p == -1 || pairs[i][0] > pairs[p][1]) {
            take = 1 + solve(pairs, i+1, i, n, t);
        }

        int skip = solve(pairs, i+1, p, n, t);

        if(p != -1) {
            t[i][p] = max(take, skip);
        }

        return max(take, skip);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();

        // sort is required for this: as stated -> select pairs in any order
        sort(begin(pairs), end(pairs));

        int maxLIS = 1;
        vector<int> t(n+1, 1);

        for(int i=0; i<n; i++) {

            for(int j=0; j<i; j++) {

                if(pairs[i][0] > pairs[j][1]) {

                    t[i]   = max(t[i], t[j]+1);
                    maxLIS = max(maxLIS, t[i]);
                }
            }
        }

        return maxLIS;
        
        // vector<vector<int>> t(n+1, vector<int>(n+1, -1));

        // return solve(pairs, 0, -1, n, t);
    }
};