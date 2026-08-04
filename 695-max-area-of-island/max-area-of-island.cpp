class Solution {
public:
    int dfs(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<bool>> &vis){
        if(i<0 || j<0 || j>=m || i>=n || grid[i][j]!=1 || vis[i][j]){
            return 0;
        }
         vis[i][j] = true;
       return 1+dfs(i+1, j,n,m, grid, vis)+ dfs(i-1, j,n,m, grid, vis)+ dfs(i, j+1,n,m, grid, vis)+ dfs(i, j-1,n,m, grid, vis);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    ans = max(ans, dfs(i, j, n, m, grid, vis));
                }
            }
        }
        return ans;
    }
};