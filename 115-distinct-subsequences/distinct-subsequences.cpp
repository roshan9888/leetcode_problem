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

    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        // return solve(n-1,m-1,s,t);
        
        //top down dp 
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return topdown(n-1,m-1,s,t,dp);
    }
};