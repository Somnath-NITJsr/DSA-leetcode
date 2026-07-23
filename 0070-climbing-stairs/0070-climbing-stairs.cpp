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

        if(n == 0 || n == 1 || n == 2) {
            return n;
        }

        vector<int> arr(n+1);
        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 2;

        // now calculate after i = 2
        for(int i=3; i<=n; i++) {
            arr[i] = arr[i-1] + arr[i-2];
        }

        return arr[n];
        
        // int t[46];
        // memset(t, -1, sizeof(t));

        // return solve(n, t);

    }
};