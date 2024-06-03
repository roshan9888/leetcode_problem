class Solution {
public:
    void dfs(int sr,int sc,vector<vector<int>>&vis,vector<vector<char>>&board
    ,int drow[],int dcol[]){
        int n=board.size();
        int m=board[0].size();
        vis[sr][sc]=1;
        for(int i=0;i<4;i++){
            int nrow=sr+drow[i];
            int ncol=sc+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && board[nrow][ncol]=='O'){
                dfs(nrow,ncol,vis,board,drow,dcol);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        //for first row and last row
        for(int i=0;i<m;i++){
            if(!vis[0][i] && board[0][i]=='O'){
                dfs(0,i,vis,board,drow,dcol);
            }

            if(!vis[n-1][i] && board[n-1][i]=='O'){
                dfs(n-1,i,vis,board,drow,dcol);
            }
        }

        //for first col and last col
        for(int j=0;j<n;j++){
            if(!vis[j][0] && board[j][0]=='O'){
                dfs(j,0,vis,board,drow,dcol);
            }

            if(!vis[j][m-1] && board[j][m-1]=='O'){
                dfs(j,m-1,vis,board,drow,dcol);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};