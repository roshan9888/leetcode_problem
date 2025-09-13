class Solution {
public:
    bool top(int src,vector<vector<int>>&adj,vector<int>&vis,stack<int>&s){
        vis[src]=1;
        for(auto it:adj[src]){
            if(vis[it]==0){
                if(top(it,adj,vis,s)) return true;
            }
            else if(vis[it]==1){
                return true;
            }
        }
        vis[src]=2;
        s.push(src);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<int>res;
        stack<int>st;
        vector<int>vis(n,0);
        vector<vector<int>>adj(n);

        for(auto e:prerequisites){
            adj[e[0]].push_back(e[1]);
        }

        for(int i=0;i<n;i++){
            if(vis[i]==0){
               if(top(i,adj,vis,st)){
                return {};
               }
            }
        }
        
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};