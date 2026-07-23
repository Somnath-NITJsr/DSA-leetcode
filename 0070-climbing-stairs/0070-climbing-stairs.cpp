class Solution {
public:
    int solve(int n, int t[]) {
        if(n < 0) {
            return 0;
        }

        if(t[n] != -1) {
            return t[n];
        }

        if(n == 0 ) {
            return 1;
        }

        int one_step = solve(n-1, t);
        int two_step = solve(n-2, t);

        return t[n] = one_step + two_step;
    }
    int climbStairs(int n) {
        
        int t[46];
        memset(t, -1, sizeof(t));

        return solve(n, t);

    }
};