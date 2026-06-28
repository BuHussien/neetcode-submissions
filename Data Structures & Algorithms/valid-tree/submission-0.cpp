class Solution {
   public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> res = bfs(adj);
        return res.size() == n;
    }
    vector<int> bfs(vector<vector<int>>& adj) {
        int V = adj.size();
        if (V == 0) return {};
        vector<bool> visited(V, false);
        vector<int> res;
        queue<int> q;
        int src = 0;
        visited[src] = true;
        q.push(src);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            res.push_back(curr);

            for (int x : adj[curr]) {
                if (!visited[x]) {
                    visited[x] = true;
                    q.push(x);
                }
            }
        }
        return res;
    }
};