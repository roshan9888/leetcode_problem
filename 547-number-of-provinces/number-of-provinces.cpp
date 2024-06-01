class Solution {
public:
    void traverse(int node,vector<vector<int>>adj,vector<int>&vis){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                traverse(it,adj,vis);
                vis[it]=1;
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int count=0;
        int n=isConnected.size();
        vector<int>vis(n,0);
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
            if(isConnected[i][j]==1 && i!=j){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
           }
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                traverse(i,adj,vis);
            }
        }
        return count;
    }
};