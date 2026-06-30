class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> >pq;

        unordered_map<int, vector<pair<int, int>>> adj;

        for(auto& edge : times) {
            int u  = edge[0];
            int v  = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt}); // directed graph
        }
        int V = n;

        vector<int> result(V+1, 1e9);
        result[k] = 0;
        pq.push({0, k});

        while(!pq.empty()) {
            int dist = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            for(auto& v: adj[node]) {
                int adjNode = v.first;
                int d       = v.second;

                if(dist + d > result[adjNode]) continue;

                if(dist + d < result[adjNode]) {
                    result[adjNode] = dist + d;
                    pq.push({result[adjNode], adjNode});
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(result[i] == 1e9)
                return -1;
            ans = max(ans, result[i]);
        }
        return ans;
    }
};