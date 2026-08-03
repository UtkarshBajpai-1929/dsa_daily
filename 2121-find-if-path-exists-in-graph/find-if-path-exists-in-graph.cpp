class Solution {
public:
    void isPath(vector<vector<int>>& adj, int source, vector<bool> &vis){
        vis[source] = true;

        for(auto v : adj[source]){
            if(!vis[v]){
                isPath(adj, v, vis);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n, false);
        isPath(adj, source, vis);
        if(vis[destination]) return true;
        return false;
    }
};