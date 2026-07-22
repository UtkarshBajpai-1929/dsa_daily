class Solution {
public:
      bool isCycle(int curr, vector<bool> &vis, vector<bool> &rPath, vector<vector<int>> &adj){
        vis[curr] = true;
        rPath[curr] = true;

        for(int v: adj[curr]){
                if(!vis[v]){
                    if(isCycle(v, vis, rPath, adj)){
                        return true;
                    }
                }else if(rPath[v]){
                        return true;
                    }
        }
        rPath[curr] = false;
        return false;
    }

    void order(int src, vector<bool> &vis, vector<vector<int>> &adj, stack<int> &st){
        vis[src] = true;
        for(int v: adj[src]){
                if(!vis[v]){
                    order(v, vis, adj, st);
                }
        }
        st.push(src);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i=0; i<prerequisites.size(); i++){
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            adj[u].push_back(v);
        }
        int n = numCourses;
        vector<bool> vis(n, false);
        vector<bool>rPath(n, false);
        stack<int> st;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                if(isCycle(i, vis, rPath, adj)){
                    return {};
                }
            }
        }
        fill(vis.begin(), vis.end(), false);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                order(i, vis, adj,st);
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};