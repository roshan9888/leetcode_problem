class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&matrix){
        if(i<0 || j>=matrix.size()) return INT_MAX;
        if(i==0){
            return matrix[i][j];
        }
        int up=solve(i-1,j,matrix);
        if(up!=INT_MAX){
            up+=matrix[i][j];
        }
        int leftdi=solve(i-1,j-1,matrix);
        if(leftdi!=INT_MAX){
           leftdi+=matrix[i][j];
        }
        int rightdi=solve(i-1,j+1,matrix);
        if(rightdi!=INT_MAX){
            rightdi+=matrix[i][j];
        }
        return min(up,min(leftdi,rightdi));
    }
    
    int topdown(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&dp){
        if(i<0 || j>=matrix.size()) return INT_MAX;
        if(i==0){
            return matrix[i][j];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int up=topdown(i-1,j,matrix,dp);
        if(up!=INT_MAX){
            up+=matrix[i][j];
        }
        int leftdi=topdown(i-1,j-1,matrix,dp);
        if(leftdi!=INT_MAX){
           leftdi+=matrix[i][j];
        }
        int rightdi=topdown(i-1,j+1,matrix,dp);
        if(rightdi!=INT_MAX){
            rightdi+=matrix[i][j];
        }
        return dp[i][j]=min(up,min(leftdi,rightdi));
    }

    int bottomup(int n,int k,vector<vector<int>>&matrix,vector<vector<int>>&dp){
        //base case
        for(int i=0;i<matrix.size();i++){
            dp[0][i]=matrix[0][i];
        }
        
        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                int up=matrix[i][j]+dp[i-1][j];

                int leftdi;
                if(j-1>=0){
                    leftdi=matrix[i][j]+dp[i-1][j-1];
                }
                else{
                    leftdi=INT_MAX;
                }

                int rightdi;
                if(j+1<matrix[0].size()){
                    rightdi=matrix[i][j]+dp[i-1][j+1];
                }
                else{
                    rightdi=INT_MAX;
                }

                dp[i][j]=min(up,min(leftdi,rightdi));
            }
        }

        return dp[n][k];
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        // int mini=INT_MAX;
        // for(int i=0;i<n;i++){
        //     mini=min(solve(n-1,i,matrix),mini);
        // }
        // return mini;

        //topdown dp
        // int mini=INT_MAX;
        // for(int i=0;i<n;i++){
        //     vector<vector<int>>dp(n,vector<int>(n,-1));
        //     mini=min(topdown(n-1,i,matrix,dp),mini);
        // }
        // return mini;
        
        //bottom up
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            vector<vector<int>>dp(n,vector<int>(n,0));
            mini=min(bottomup(n-1,i,matrix,dp),mini);
        }
        return mini;
    }
};