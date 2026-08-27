class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.length();

        if(n == 1) {
            return "";
        }


        // n/2 because, the first half will be the mirror image of the rest
        for(int i=0; i<n/2; i++) {

            if(palindrome[i] != 'a') {
                // change the first letter to a, to make a non palindrome
                // lexiographically
                palindrome[i] = 'a';
                return palindrome;
            }
        }

        // if all a a a a a, then change the last letter to b, to maintain the lexiographicall order
        palindrome[n-1] = 'b';
        return palindrome;
    }
};