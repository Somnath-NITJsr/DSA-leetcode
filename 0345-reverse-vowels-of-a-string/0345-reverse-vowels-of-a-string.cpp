class Solution {
public:
    bool is_vowel(char s) {
        if ((s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u') ||
            (s == 'A' || s == 'E' || s == 'I' || s == 'O' || s == 'U'))
            return true;

        return false;
    }

    string reverseVowels(string s) {
        int n = s.length();
        int i = 0;
        int j = n-1;

        while(i < j) {

            if(is_vowel(s[i]) && is_vowel(s[j])) {
                swap(s[i], s[j]);
                i++;
                j--;
            } else if(is_vowel(s[i])) {
                j--;
            } else {
                i++;
            }
        }
        return s;
    }
};