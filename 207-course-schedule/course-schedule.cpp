class Solution {
public:
    bool isCycle(int curr, vector<bool> &vis, vector<bool> &rPath, vector<vector<int>> &prerequisites){
        vis[curr] = true;
        rPath[curr] = true;

        for(int i=0; i<prerequisites.size(); i++){
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];

            if(curr == u){
                if(!vis[v]){
                    if(isCycle(v, vis, rPath, prerequisites)){
                        return true;
                    }
                }else if(rPath[v]){
                        return true;
                    }
            }
        }
        rPath[curr] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<bool> vis(n, false);
        vector<bool> rPath(n, false);
        for(int i=0; i<n; i++){
            if(!vis[i]){
            if(isCycle(i, vis, rPath, prerequisites)){
                return false;
            }
            }
        }
        return true;
    }
};