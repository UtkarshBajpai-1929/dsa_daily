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

    void order(int src, vector<bool> &vis, vector<vector<int>> &prerequisites, stack<int> &st){
        vis[src] = true;
        for(int i=0; i<prerequisites.size(); i++){
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];

            if(src==u){
                if(!vis[v]){
                    order(v, vis, prerequisites, st);
                }
            }
        }
        st.push(src);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<bool> vis(n, false);
        vector<bool>rPath(n, false);
        stack<int> st;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                if(isCycle(i, vis, rPath, prerequisites)){
                    return {};
                }
            }
        }
        fill(vis.begin(), vis.end(), false);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                order(i, vis, prerequisites,st);
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