class Solution {
public: 
    int solve(int i,int j,string&s,string&t){
        if(j<0){
            return 1;
        }

        if(i<0) return 0;

        if(s[i]==t[j]){
            return solve(i-1,j-1,s,t)+solve(i-1,j,s,t);
        }
        else{
            return solve(i-1,j,s,t);
        }
    }

    int topdown(int i,int j,string&s,string&t,vector<vector<int>>&dp){
        if(j<0){
            return 1;
        }

        if(i<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j]=topdown(i-1,j-1,s,t,dp)+topdown(i-1,j,s,t,dp);
        }
        else{
            return dp[i][j]=topdown(i-1,j,s,t,dp);
        }
    }

    int bottomup(int n,int m,string&s,string&t,vector<vector<double>>&dp){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                   dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return (int)dp[n][m];
    }

    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        // return solve(n-1,m-1,s,t);
        
        //top down dp 
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return topdown(n-1,m-1,s,t,dp);

        //bottom up dp
        vector<vector<double>>dp(n+1,vector<double>(m+1,0));
        for(int i=0;i<=n;i++) dp[i][0]=1;
        for(int j=1;j<=m;j++) dp[0][j]=0;
        return bottomup(n,m,s,t,dp);
    }
};