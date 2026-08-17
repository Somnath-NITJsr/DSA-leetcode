class Solution {
public:
    void solve(string& curr, int& n, vector<string>& result) {

        auto isValid = [&](string& curr) {
            int count = 0;
            for(int i=0; i<curr.length(); i++) {

                if(curr[i] == '(') {
                    count++;
                } else {
                    count--;
                }

                if(count < 0) {
                    return false;
                }
            }

            return count == 0;
        };

        if(curr.length() == 2*n) {

            if(isValid(curr)) {
                result.push_back(curr);
            }
            return;
        }

        // push, explore, pop
        curr.push_back('(');
        solve(curr, n, result);
        curr.pop_back();

        curr.push_back(')');
        solve(curr, n, result);
        curr.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string curr = "";

        solve(curr, n, result);
        return result;
    }
};