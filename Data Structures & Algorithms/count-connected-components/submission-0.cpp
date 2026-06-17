class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<bool>visited(n,false);
        int component = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                component++;
                dfs(i, adj, visited);
            }
        }
        return component;
    }
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited){
        visited[node] = true;
        for(int x : adj[node])
            if(!visited[x])
                dfs(x,adj,visited);
    }
};
