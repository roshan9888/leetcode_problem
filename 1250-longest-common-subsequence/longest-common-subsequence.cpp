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

    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        // return solve(n-1,m-1,text1,text2);

        //topdown dp
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return topdown(n-1,m-1,text1,text2,dp);
    }
};