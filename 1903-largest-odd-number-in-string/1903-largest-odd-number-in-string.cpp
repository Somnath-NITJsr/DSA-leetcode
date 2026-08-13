class Solution {
public:
    string largestOddNumber(string num) {
        int n =  num.length();
        int i = n - 1;;
        for(; i >= 0; i--) {

            if(num[i] & 1) {
                break;
            }
        }
        
        return num.substr(0, i+1);
    }
};