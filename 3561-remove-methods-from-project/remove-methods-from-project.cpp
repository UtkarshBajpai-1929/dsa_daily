class Solution {
public:
    void dfs(int k, vector<vector<int>> &adj, vector<bool> &vis){
        vis[k] = true;
        for(auto edge: adj[k]){
            if(!vis[edge]){
                dfs(edge, adj,vis);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for(int i=0; i<invocations.size(); i++){
            int u = invocations[i][0];
            int v = invocations[i][1];
            adj[u].push_back(v);
        }
        vector<bool> vis(n, false);
         dfs(k, adj, vis);
        for(int i=0; i<invocations.size(); i++){
            int u = invocations[i][0];
            int v = invocations[i][1];
            if(!vis[u] && vis[v]){
                vector<int> ans;
                for(int i=0; i<n; i++){
                    ans.push_back(i);
                }
                return ans;
            }
        }
        vector<int>ans;
       for(int i=0; i<n; i++){
        if(!vis[i]){
            ans.push_back(i);
        }
      }
      return ans;
    }
};