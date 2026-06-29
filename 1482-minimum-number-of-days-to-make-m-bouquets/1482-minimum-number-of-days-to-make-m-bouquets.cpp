class Solution {
public:
    bool isPossible(vector<int>& bloomDay, int time, int& m, int& k) {

        int consecutive_flowers = 0;
        int bouquets_made = 0;

        for (int i = 0; i < bloomDay.size(); i++) {

            if (bloomDay[i] <= time) {
                consecutive_flowers++;

                if (consecutive_flowers == k) {
                    bouquets_made++;
                    consecutive_flowers = 0;
                }
            } else {
                consecutive_flowers = 0;
            }
        }
        return bouquets_made >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        int l = *min_element(begin(bloomDay), end(bloomDay));
        int r = *max_element(begin(bloomDay), end(bloomDay));
        int ans = -1;

        while (l <= r) {

            int mid = l + (r - l) / 2;

            if (isPossible(bloomDay, mid, m, k)) {
                r   = mid - 1;
                ans = mid;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};