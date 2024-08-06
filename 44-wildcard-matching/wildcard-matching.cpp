class Solution {
public: 
    bool solve(int i,int j,string &s,string &p){
        if(i<0 && j<0) return true;
        if(j<0 && i>=0) return false;
        if(i<0 && j>=0){
            for(int t=0;t<=j;t++){
                if(p[t]!='*') return false;
            }
            return true;
        }

        if(s[i]==p[j] || p[j]=='?'){
            return solve(i-1,j-1,s,p);
        }
        if(p[j]=='*') return solve(i-1,j,s,p) | solve(i,j-1,s,p);

        return false;
    }

    bool topdown(int i,int j,string &s,string &p,vector<vector<int>>&dp){
        if(i<0 && j<0) return true;
        if(j<0 && i>=0) return false;
        if(i<0 && j>=0){
            for(int t=0;t<=j;t++){
                if(p[t]!='*') return false;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j] || p[j]=='?'){
            return dp[i][j]=topdown(i-1,j-1,s,p,dp);
        }
        if(p[j]=='*') return dp[i][j]=topdown(i-1,j,s,p,dp) | topdown(i,j-1,s,p,dp);

        return false;
    }

    bool bottomup(int n,int m,string &s,string &p,vector<vector<bool>>&dp){
        dp[0][0]=true; 
        for(int i=1;i<=n;i++){
            dp[i][0]=false;
        }
        for(int j=1;j<=m;j++){
            bool flag=true;
            for(int i=1;i<=j;i++){
                if(p[i-1]!='*'){
                    flag=false;
                    break;
                }
            }
            dp[0][j]=flag;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
        if(s[i-1]==p[j-1] || p[j-1]=='?'){
            dp[i][j]=dp[i-1][j-1];
        }
        else if(p[j-1]=='*') dp[i][j]=dp[i-1][j] | dp[i][j-1];
        else dp[i][j]=false;
        }
        }
        return dp[n][m];
    }

    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        // return solve(n-1,m-1,s,p);

        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // return topdown(n-1,m-1,s,p,dp);

        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        return bottomup(n,m,s,p,dp);
    }
};