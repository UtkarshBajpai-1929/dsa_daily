class Solution {
public:
    void dfs(int i, int j, int n, int m, vector<vector<int>> &grid, vector<vector<bool>> &vis){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]!=1 || vis[i][j]){
            return;
        }
        grid[i][j] = 2;

        dfs(i+1, j, n, m, grid, vis);
        dfs(i-1, j, n, m, grid, vis);
        dfs(i, j+1, n, m, grid, vis);
        dfs(i, j-1, n, m, grid, vis);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for(int i=0; i<n; i++){
            if(grid[i][0] == 1){
                dfs(i, 0, n, m, grid, vis);
            }
            if(grid[i][m-1] == 1){
                 dfs(i, m-1, n, m, grid, vis);
            }
        }
        for(int j=0; j<m; j++){
            if(grid[0][j] == 1){
                dfs(0, j, n, m, grid, vis);
            }
            if(grid[n-1][j] == 1){
               dfs(n-1, j, n, m, grid, vis);
            }
        } 
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    ans++;
                }
            }
        }
        return ans;
    }
};