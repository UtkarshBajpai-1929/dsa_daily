class Solution {
public:
    int time = 0;
    vector<int> dt, low;
    void dfs(int u, int par, vector<int> &vis, vector<vector<int>> &adj, vector<vector<int>>& ans){
        vis[u] = true;
        dt[u] = low[u] = ++time;
        for(auto v: adj[u]){
            if(!vis[v]){
                dfs(v, u,vis, adj, ans);
                low[u] = min(low[v], low[u]);
                if(low[v] > dt[u]){
                    ans.push_back({u, v});
                }
            }else if(v != par){
                low[u] = min(dt[v], low[u]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(int i=0; i<connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dt.resize(n);
        low.resize(n);
        vector<int> vis(n, false);
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                   dfs(i, -1, vis, adj, ans);
            }
        }
        return ans;
    }
};