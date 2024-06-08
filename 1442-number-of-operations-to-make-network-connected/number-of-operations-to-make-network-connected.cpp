class disjoint_set{
    vector<int>rank,parent;
public:
    disjoint_set(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findUPar(int node){
        if(node==parent[node])
          return node;
        return parent[node]=findUPar(parent[node]);
    }

    bool unionByRank(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u!=ulp_v){
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
        return true;
        }
        return false;
    }

};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        disjoint_set ds(n);
        int tcount=0;
        int fcount=0;
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            if(ds.unionByRank(u,v)){
                tcount++;
            }
            else{
                fcount++;
            }
        }
        cout<<fcount<<" ";
        cout<<tcount<<" ";
        if(fcount==(n-(tcount+1))){
            return fcount;
        }
        else if(fcount>(n-(tcount+1))){
            return (n-(tcount+1));
        }
        return -1;
    }
};