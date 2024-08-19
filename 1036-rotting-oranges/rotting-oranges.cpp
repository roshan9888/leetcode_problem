class Solution {
public:
    int rotten(vector<vector<int>>&grid){
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    visited[i][j]=2;
                }
            }
        }

        int tm=0;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int t=q.front().second;
            tm=max(tm,t);
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1
                && visited[nrow][ncol]==0){
                    q.push({{nrow,ncol},t+1});
                    visited[nrow][ncol]=2;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]!=2 && grid[i][j]==1){
                    return -1;
                }
            }
        }
        return tm;





























        // int n=grid.size();
        // int m=grid[0].size();
        // vector<vector<int>>visited(n,vector<int>(m,0));
        // queue<pair<pair<int,int>,int>>q;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(grid[i][j]==2){
        //             q.push({{i,j},0});
        //             visited[i][j]=2;
        //     }
        //         }
        //     }

        //     int tm=0;
        //     int drow[]={-1,0,1,0};
        //     int dcol[]={0,1,0,-1};
        //     while(!q.empty()){
        //     int row=q.front().first.first;
        //     int col=q.front().first.second;
        //     int t=q.front().second;
        //     tm=max(tm,t);
        //     q.pop();
        //     for(int i=0;i<4;i++){
        //         int nrow=row+drow[i];
        //         int ncol=col+dcol[i];
        //         if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && 
        //         visited[nrow][ncol]==0)
        //         {
        //            q.push({{nrow,ncol},t+1});
        //            visited[nrow][ncol]=2;
        //         }
        //     }
        //     }

        //     for(int i=0;i<n;i++){
        //         for(int j=0;j<m;j++){
        //             if(visited[i][j]!=2 && grid[i][j]==1){
        //                 return -1;
        //             }
        //         }
        //     }
        //     return tm;
        } 
    int orangesRotting(vector<vector<int>>& grid) {
        return rotten(grid);
    }
};