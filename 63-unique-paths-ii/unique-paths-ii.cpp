class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&Grid){    
        if(i>=0 && j>=0 && Grid[i][j]==1) return 0;    
        if(i==0 && j==0){
            return 1;
        }

        if(i<0 || j<0) return 0;

        int left=solve(i,j-1,Grid);
        int up=solve(i-1,j,Grid);
        return left+up;
    }

    int topdown(int i,int j,vector<vector<int>>&Grid,vector<vector<int>>&dp){    
        if(i>=0 && j>=0 && Grid[i][j]==1) return 0;    
        if(i==0 && j==0){
            return 1;
        }

        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int left=topdown(i,j-1,Grid,dp);
        int up=topdown(i-1,j,Grid,dp);
        return dp[i][j]=left+up;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        // return solve(m-1,n-1,obstacleGrid);
   
        //top down 
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return topdown(m-1,n-1,obstacleGrid,dp);
    }
};