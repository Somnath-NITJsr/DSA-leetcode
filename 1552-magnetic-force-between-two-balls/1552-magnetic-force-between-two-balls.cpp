class Solution {
public:
    int n;
    bool canPlace(vector<int>& position, int mid, int& m) {

        int ballsPlaced = 1;
        int lastPosition = position[0];

        for(int i=0; i<n; i++) {
                if(abs(position[i] - lastPosition) >= mid) {
                    ballsPlaced++;
                    lastPosition = position[i];
                }               
        }
        return ballsPlaced >= m;
    }
    int maxDistance(vector<int>& position, int m) {
        n = position.size();
        int l = 1;
        int r = *max_element(begin(position), end(position));
        int ans = 1;
        sort(begin(position), end(position));

        while(l <= r) {

            int mid = l + (r-l)/2;

            if(canPlace(position, mid, m)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};