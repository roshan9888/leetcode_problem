class Solution {
public:
    bool dfs(int node,vector<int>&color,int col,vector<vector<int>>&graph){
        color[node]=col;
        for(auto it:graph[node]){
            if(color[it]==-1){
               if(dfs(it,color,!col,graph)==false) return false;
            }
            else if(color[it]==col){
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1 && dfs(i,color,0,graph)==false) return false;
        }
        return true;
    }
};