class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int m = edges.size();
         int n = 0;

        for (auto &edge : edges) {
          n = max(n, max(edge[0], edge[1]));
        }
        vector<vector<int>> adj(n + 1);
        for(int i=0; i<m; i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans = -1;
        for(int i=1; i<=n; i++){
            if(adj[i].size() == n-1){
                ans = i;
            }
        }
        return ans;
    }
};