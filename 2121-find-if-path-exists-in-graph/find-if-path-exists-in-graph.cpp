class Solution {
public:
    bool dfs(vector<vector<int>>&adj,int source,int destination,vector<bool>&visited){
        if(source==destination) return true;
        visited[source]=true;
        for(int n:adj[source]){
            if(!visited[n]){
                if(dfs(adj,n,destination,visited)){
                    return true;
                }
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool>visited(n,false);
        vector<vector<int>>adj(n);
        for(auto&e:edges){
           adj[e[0]].push_back(e[1]);
           adj[e[1]].push_back(e[0]);
        }
        
        // for(int i=0;i<n;i++){
        //     cout<<i<<"->";
        //     for(auto it:adj[i]){
        //         cout<<it<<endl;
        //     }
        // }
        return dfs(adj,source,destination,visited);
    }
};