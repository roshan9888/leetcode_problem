class Solution {
public:
    int solve(int i,int j,string &word1,string &word2){
        if(i<0) return j+1;
        if(j<0) return i+1;

        if(word1[i]==word2[j]){
            return solve(i-1,j-1,word1,word2);
        }
        else{
            return 1+min(solve(i,j-1,word1,word2),min(solve(i-1,j,word1,word2),solve(i-1,j-1,word1,word2))); //insert
            // return 1+solve(i-1,j,word1,word2);  //delete
            // return 1+solve(i-1,j-1,word1,word2); //replace
        }
    }

    int topdown(int i,int j,string &word1,string &word2,vector<vector<int>>&dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]){
            return dp[i][j]=topdown(i-1,j-1,word1,word2,dp);
        }
        else{
            return dp[i][j]=1+min(topdown(i,j-1,word1,word2,dp),min(topdown(i-1,j,word1,word2,dp),topdown(i-1,j-1,word1,word2,dp))); //insert
            // return 1+solve(i-1,j,word1,word2);  //delete
            // return 1+solve(i-1,j-1,word1,word2); //replace
        }
    }

    int bottomup(int n,int m,string &word1,string &word2,vector<vector<int>>&dp){
        for(int i=0;i<=n;i++) dp[0][i]=i;
        for(int j=0;j<=m;j++) dp[j][0]=j;
         
        for(int i=1;i<-n;i++){
            for(int j=0;j<=m;j++){
                if(word1[i]==word2[j]){
                dp[i][j]=dp[i-1][j-1];
        }
        else{
            dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1])); //insert
        }
            }
        }
        return dp[n][m];
    }

    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        // return solve(n,m,word1,word2);

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return topdown(n-1,m-1,word1,word2,dp);

        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // return topdown(n-1,m-1,word1,word2,dp);
    }
};