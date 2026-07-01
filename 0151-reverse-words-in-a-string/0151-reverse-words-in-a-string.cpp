class Solution {
public:
    string reverseWords(string s) {
        
        reverse(begin(s), end(s));
        int n = s.length();
        
        int i = 0;        
        int l = 0, r = 0;


        while(i < n) {
            
            while(i < n && s[i] != ' ') {
                s[r++] = s[i++];
            }         

            if(l < r) {
                reverse(begin(s) + l, begin(s) + r); 
                // after reversing , then r will assign a space
                s[r++] = ' ';
                
                l = r;
            }

            i++;
        }
        return s.substr(0, r-1);        
          
        
        
        
        /*

         - NOT TO BE USED IN THE INTERVIEW

        stringstream ss(s);

        string token  = "";
        string result = "";

        while(ss >> token) {

            result = token + " " + result;
        }

        int n = result.size();
        return result.substr(0, n-1);
        */
    }
};