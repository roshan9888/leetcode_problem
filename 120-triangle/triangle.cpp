class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&triangle){
        if(i==triangle.size()-1) return triangle[i][j];

        int down=triangle[i][j]+solve(i+1,j,triangle);
        int dia=triangle[i][j]+solve(i+1,j+1,triangle);

        return min(down,dia);
    }

    int topdown(int i,int j,vector<vector<int>>&triangle,vector<vector<int>>&dp){
        if(i==triangle.size()-1) return triangle[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int down=triangle[i][j]+topdown(i+1,j,triangle,dp);
        int dia=triangle[i][j]+topdown(i+1,j+1,triangle,dp);

        return dp[i][j]=min(down,dia);
    }

    int bottomup(int n,vector<vector<int>>&triangle,vector<vector<int>>&dp){
        for(int j=0;j<n;j++){
            dp[n-1][j]=triangle[n-1][j];
        }

        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
               int down=triangle[i][j]+dp[i+1][j];
               int dia=triangle[i][j]+dp[i+1][j+1];
               dp[i][j]=min(down,dia);
            }
        }
        return dp[0][0];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        // return solve(0,0,triangle);

        //top down dp
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        // return topdown(0,0,triangle,dp);

        //bottom up dp
        vector<vector<int>>dp(n,vector<int>(n,0));
        return bottomup(n,triangle,dp);
    }
};