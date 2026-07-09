class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<int> result(n, 1e9);

        unordered_map<int, vector<pair<int, int>> > adj;

        for(auto& vec : flights) {
            int u = vec[0];
            int v = vec[1];
            int c = vec[2];

            adj[u].push_back({v, c}); // u ---> v at cost c
        }

        queue<pair<int, int>> q;
        // src, cost
        q.push({src, 0});

        // result of src to src = 0;
        result[src] = 0;

        // keep track of the steps <= k
        int steps = 0;

        while(!q.empty() && steps <= k) {
            int N = q.size();

            while(N--) {

                auto& it = q.front();

                int node = it.first;
                int cost = it.second;
                q.pop();

                for(auto& v : adj[node]) {

                    int adjNode = v.first;
                    int dist    = v.second;

                    if(dist + cost < result[adjNode]) {
                        result[adjNode] = dist + cost;

                        q.push({adjNode, dist + cost});
                    }
                }
            }
            steps++;
        }

        if(result[dst] == 1e9) {
            return -1;
        }

        return result[dst];
    }
};