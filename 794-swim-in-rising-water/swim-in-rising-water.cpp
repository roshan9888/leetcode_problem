class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        pq.push({grid[0][0],0,0});
        visited[0][0]=1;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int elevation=it[0];
            int x=it[1];
            int y=it[2];
            
            if(x==n-1 && y==n-1) return elevation;

            for(int i=0;i<4;i++){
                int nrow=x+dr[i];
                int ncol=y+dc[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n &&visited[nrow][ncol]==false){
                    pq.push({max(elevation,grid[nrow][ncol]),nrow,ncol});
                    visited[nrow][ncol]=1;
                }
            }
        }
        return -1;
    }
};