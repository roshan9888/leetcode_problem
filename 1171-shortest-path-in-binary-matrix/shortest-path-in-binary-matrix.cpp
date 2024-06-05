class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        if(grid[0][0]!=0) return -1;
        if(grid[0][0]==0 && grid.size()==1) return 1;
        q.push({1,{0,0}});
        int dr[]={-1,-1,0,1,1,1,0,-1};
        int dc[]={0,-1,-1,-1,0,1,1,1};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int d=it.first;
            int r=it.second.first;
            int c=it.second.second;

            for(int i=0;i<8;i++){
                int nrow=r+dr[i];
                int ncol=c+dc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==0
                && 1+d<dis[nrow][ncol]){
                    dis[nrow][ncol]=1+d;
                    if(nrow==n-1 && ncol==m-1) return 1+d;
                    q.push({dis[nrow][ncol],{nrow,ncol}});
                }
            }
        }
        return -1;
    }
};