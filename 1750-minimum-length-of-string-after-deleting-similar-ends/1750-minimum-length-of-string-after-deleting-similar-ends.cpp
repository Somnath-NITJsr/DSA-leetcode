class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        int i = 0;
        int j = n-1;

        while(i < j && s[i] == s[j]) {

            char ch = s[i]; // or s[j]

            // check how much we can take the prefix
            while(i < j && s[i] == ch) {
                i++;
            }

            // check how much we can take the suffix
            while(j >= i && s[j] == ch) {
                j--;
            }
        }
        return j - i + 1;
    }
};