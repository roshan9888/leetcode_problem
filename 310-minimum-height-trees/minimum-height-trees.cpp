class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        vector<vector<int>>adj(n);
        vector<int>deg(n,0);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            deg[e[0]]++;
            deg[e[1]]++;
        }
        
        queue<int>q;
        for(int i=0;i<n;i++){
            if(deg[i]==1) q.push(i);
        }

        vector<int>res;
        while(!q.empty()){
            int s=q.size();
            res.clear();
            for(int i=0;i<s;i++){
               int node=q.front();
               q.pop();
               res.push_back(node);
               for(auto it:adj[node]){
               deg[it]--;
               if(deg[it]==1) q.push(it
               );
               }
            }
        }
        return res;
    }
};