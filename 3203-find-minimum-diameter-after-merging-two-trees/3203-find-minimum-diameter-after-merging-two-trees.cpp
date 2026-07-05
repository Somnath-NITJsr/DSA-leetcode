class Solution {
public:
    pair<int, int> BFS(unordered_map<int, vector<int>>& adj, int u) {
        queue<int> q;
        q.push(u);

        unordered_map<int, bool> visited;
        visited[u] = true;

        int farthestNode = u;
        int distance     = 0;


        while(!q.empty()) {
            int N = q.size();

            while(N--) {
                int curr     = q.front();
                farthestNode = curr;
                q.pop();

                for(auto& neighbour : adj[curr]) {

                    if(!visited[neighbour]) {
                        visited[neighbour] = true;
                        q.push(neighbour);
                    }
                }
            }
            if(!q.empty()) {
                distance++;
            }
        }
        return {farthestNode, distance};
    }
    int findDiameter(unordered_map<int, vector<int>>& adj) {

        // find the farthest node from the random node - 0
        auto [farthestNode, dist] = BFS(adj, 0);

        // the farthest node we got from the above is the one end of the graph

        // now find the another farthest node from the farthest node, which is the diameter in final
        auto [otherNode, diameter] = BFS(adj, farthestNode);

        return diameter;
    }

    unordered_map<int, vector<int>> buildAdj(vector<vector<int>>& edges) {
        int V = edges.size();
        unordered_map<int, vector<int>> adj(V);

        for(auto& edge: edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int, vector<int>> adj1 = buildAdj(edges1);
        unordered_map<int, vector<int>> adj2 = buildAdj(edges2);

        int dia1     = findDiameter(adj1);
        int dia2     = findDiameter(adj2);
        int combined = (dia1 + 1)/2 + (dia2 + 1)/2 + 1;

        return max({dia1, dia2, combined});
    }
};