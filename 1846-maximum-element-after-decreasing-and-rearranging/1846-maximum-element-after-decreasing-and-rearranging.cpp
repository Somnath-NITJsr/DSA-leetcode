class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();

        int maxElement = -1e9;

        // 1. sort
        sort(begin(arr), end(arr));

        for(int i = 0; i < n; i++) {

            if(i == 0) {
                arr[0] = 1;
            } else if(abs(arr[i] - arr[i - 1]) > 1) {

                arr[i]     = arr[i - 1] + 1;
            }
            maxElement = max(maxElement, arr[i]);
        }

        return maxElement;
    }
};