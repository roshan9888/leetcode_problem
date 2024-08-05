class Solution {
public:
    int solve(string&a,string&b){
        vector<vector<int>>dp(a.size()+1,vector<int>(b.size()+1,0));
        for(int i=0;i<=a.size();i++) dp[i][0]=0;
        for(int j=0;j<=b.size();j++) dp[0][j]=0;
        int ans=0;
        for(int i=1;i<=a.size();i++){
            for(int j=1;j<=b.size();j++){
                if(a[i-1]==b[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
                ans=max(ans,dp[i][j]);
            }
        }
        return a.size()-ans+b.size()-ans;
    }

    int minDistance(string word1, string word2) {
        string a=word1;
        string b=word2;
        return solve(a,b);
    }
};