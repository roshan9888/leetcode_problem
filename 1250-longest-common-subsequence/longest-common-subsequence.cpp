class Solution {
public:
    int solve(int i,int j,string &s1,string &s2){
        if(i<0 || j<0 ) return 0;

        if(s1[i]==s2[j]) return 1+solve(i-1,j-1,s1,s2);
        return max(solve(i-1,j,s1,s2),solve(i,j-1,s1,s2));
    }

    int topdown(int i,int j,string &s1,string &s2,vector<vector<int>>&dp){
        if(i<0 || j<0 ) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j]=1+topdown(i-1,j-1,s1,s2,dp);
        return dp[i][j]=max(topdown(i-1,j,s1,s2,dp),topdown(i,j-1,s1,s2,dp));
    }
    
    int bottomup(int n,int m,string &s1,string &s2,vector<vector<int>>&dp){
        // if(i<0 || j<0 ) return 0;
        // if(dp[i][j]!=-1) return dp[i][j];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
    
    int space(int n,int m,string &s1,string &s2){
        vector<int>prev(m+1,0),curr(m+1,0);

        for(int i=0;i<=m;i++) prev[i]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]) curr[j]=1+prev[j-1];
                else curr[j]=max(prev[j],curr[j-1]);
            }
            prev=curr;
        }
        return prev[m];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        // return solve(n-1,m-1,text1,text2);

        //topdown dp
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return topdown(n-1,m-1,text1,text2,dp);

        // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // for(int i=0;i<=n;i++) dp[i][0]=0;
        // for(int j=0;j<=m;j++) dp[0][j]=0;
        // return bottomup(n,m,text1,text2,dp);

        return space(n,m,text1,text2);
    }
};