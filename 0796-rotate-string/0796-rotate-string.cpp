class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        int m = goal.length();

        if(n != m) {
            return false;
        }

        for(int i=0; i<n; i++) {

            rotate(begin(s), begin(s) + 1, end(s));
            // start of the range, which position will become the starting position of the range, end of the range.
        
            if(s == goal) {
                return true;
            }
        }

        return false;
    }
};