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
        // int count = 0;
        // Capturing [&] lets you use s and n directly:
        // auto checkPal = [&](int i, int j) {

        //     while(i >= 0 && j < n && s[i] == s[j]) {
        //         count++;
        //         i--;
        //         j++;
        //     }

        // };

        // for(int i=0; i<n; i++) {
        //     // we don't need to pass the s, i as we are using the [&]..
        //     checkPal(i, i);
        //     checkPal(i, i+1);
        // }


        // return count;
        
        // BLUE PRINT

        int count = 0;
        vector<vector<bool>> t(n, vector<bool>(n, false));

        for(int L=1; L<=n; L++) {

            for(int i=0; i+L-1<n; i++) {

                int j = i+L-1; // i = 0 , L = 2 , j = 2 - 1 + 0 = 1

                if(i == j) { // diagonal entries are always true, single element
                    t[i][i] = true;
                } else if(i+1 == j) { // length = 2, if palindrome then true
                    t[i][j] = (s[i] == s[j]); 
                } else { // length > 2
                    t[i][j] = (s[i] == s[j]) && t[i+1][j-1]; 
                    // check the i, j and i+1, j-1 part
                }

                // after all if its true, then the substring is a palindrome
                if(t[i][j] == true) {
                    count++;
                }
            }
        }

        return count;

        // for the REC + MEMO;
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