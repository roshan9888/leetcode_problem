class Solution {
public:
    int solve(int i,int j){
        if(i==0 && j==0){
            return 1;
        }

        if(i<0 || j<0) return 0;

        int left=solve(i,j-1);
        int up=solve(i-1,j);
        return left+up;
    }

    int topdown(int i,int j,vector<vector<int>>&dp){
        if(i==0 && j==0){
            return 1;
        }

        if(i<0 || j<0) return 0;

        if(dp[i][j]!=-1) return dp[i][j]; 
        int left=topdown(i,j-1,dp);
        int up=topdown(i-1,j,dp);
        return dp[i][j]=left+up;
    }

    int bottomup(int m,int n,vector<vector<int>>&dp){
        dp[0][0]=1;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;
                else{
                    int left=j>0 ? dp[i][j-1] : 0;
                    int up=i > 0 ? dp[i-1][j] : 0;
                    dp[i][j]=left+up;
                }
            }
        }
        return dp[m-1][n-1];
    }
    
    int space(int m,int n){
        vector<int>prev(n,0);
        for(int i=0;i<m;i++){
            vector<int>curr(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0) curr[j]=1;
                else{
                    int up=i > 0 ? prev[j] : 0;
                    int left=j>0 ? curr[j-1] : 0;
                    curr[j]=left+up;
                }
            }
            prev=curr;
        }
        return prev[n-1];
    }
    int uniquePaths(int m, int n) {
        // return solve(m-1,n-1);
        
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        // return topdown(m-1,n-1,dp);

        // vector<vector<int>>dp(m,vector<int>(n,0));
        // return bottomup(m,n,dp);

        //space 
        return space(m,n);
    }
};