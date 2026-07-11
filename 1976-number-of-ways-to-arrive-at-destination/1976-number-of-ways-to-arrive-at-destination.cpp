class Solution {
public:
    const int MOD = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        
        // the result vector
        vector<long long> result(n, LLONG_MAX);

        // the no of ways vector
        vector<long long> ways(n, 0);

        // the adjacent list and the populating it
        unordered_map<int, vector<pair<int, int>> >adj;
        for(auto& vec: roads) {

            int u    = vec[0];
            int v    = vec[1];
            int cost = vec[2];

            // undirected graph
            adj[u].push_back({v, cost});
            adj[v].push_back({u, cost});
        }

        // the src to src cost is 0
        result[0] = 0;
        ways[0]   = 1;


        // the legendary priority_queue
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>> >pq;
        pq.push({0, 0}); // {distance, node}


        while(!pq.empty()) {

            int N = pq.size();

            while(N--) {

                auto it = pq.top();
                pq.pop();

                long long cost = it.first;
                int node       = it.second;

                if(cost > result[node]) continue;

                for(auto& vec: adj[node]) {

                    int adjNode = vec.first;
                    int adjCost = vec.second;


                    if(cost + adjCost < result[adjNode]) {

                        result[adjNode] = adjCost + cost;
                        ways[adjNode]   = ways[node];
                        pq.push({result[adjNode], adjNode});

                    } else if(cost + adjCost == result[adjNode]) {
                        ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                    }
                }
            }
        }
        return ways[n-1];        
    }
};