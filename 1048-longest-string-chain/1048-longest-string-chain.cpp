class Solution {
public:
    bool checkPred(string& word1, string& word2) {
        int M = word1.size();
        int N = word2.size();

        if(M >= N || N-M != 1) {
            return false;
        }

        int i=0 , j=0;

        while(i < M && j < N) {
            if(word1[i] == word2[j]) {
                i++;
            }
            j++;
        }

        return i == M;
    }
    long solve(vector<string>& words, int i, int p, int& n, vector<vector<long>>& t) {
        if(i >= n) {
            return 0;
        }

        if(p != -1 && t[i][p] != -1) {
            return t[i][p];
        }

        long take = 0;

        if(p == -1 || checkPred(words[p], words[i])) {
            take = 1 + solve(words, i+1, i, n, t);
        }

        long skip = solve(words, i+1, p, n, t);

        if(p != -1) {
            t[i][p] = max(take, skip);
        }

        return max(take, skip);
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();

        auto myFun = [&](string& word1, string& word2) {
            return word1.length() < word2.length();
        };

        sort(begin(words), end(words), myFun);

        vector<int> t(n+1, 1);
        int maxLIS = 1;

        for(int i=0; i<n; i++) {
            
            for(int j=0; j<i; j++) {

                if(checkPred(words[j], words[i])) {
                    t[i]   = max(t[i], t[j] + 1);
                    maxLIS = max(maxLIS, t[i]);
                }
            }
        }
        return maxLIS;

        // vector<vector<long>> t(n+1, vector<long>(n+1, -1));

        // return solve(words, 0, -1, n, t);
    }
};