class Solution {
public:
    vector<int> dijkstra(unordered_map<int, vector<pair<int, int>>>& adj, int src, int n) {

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src}); // distance , node

        vector<int> result(n, 1e9);
        result[src] = 0;

        while (!pq.empty()) {

            auto curr = pq.top();
            int cost  = curr.first;
            int node  = curr.second;
            pq.pop();

            if (cost > result[node]) {
                continue;
            }

            for (auto& vec : adj[node]) {

                int adjNode = vec.first;
                int adjCost = vec.second;

                if (adjCost + cost < result[adjNode]) {

                    result[adjNode] = adjCost + cost;
                    pq.push({result[adjNode], adjNode});
                }
            }
        }
        return result;
    }
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {

        int E = edges.size();

        unordered_map<int, vector<pair<int, int>>> adj;

        for (auto& edge : edges) {
            int u    = edge[0];
            int v    = edge[1];
            int cost = edge[2];

            adj[u].push_back({v, cost});
            adj[v].push_back({u, cost});
        }

        vector<int> fromSrc  = dijkstra(adj, 0, n);      // src
        vector<int> fromDest = dijkstra(adj, n - 1, n); // n-1 dest

        vector<bool> result(E, false);

        for (int i = 0; i < E; i++) {

            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            int distFromSrc = fromSrc[u];
            int distFromDest = fromDest[v];

            if (distFromSrc + w + distFromDest == fromSrc[n - 1]) {
                result[i] = true;
            }

            distFromSrc  = fromSrc[v];
            distFromDest = fromDest[u];

            if (distFromSrc + w + distFromDest == fromSrc[n - 1]) {
                result[i] = true;
            }
        }
        return result;
    }
};