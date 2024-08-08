class Solution {
public:
    int solve(int i,int j,vector<int>&cuts){
        if(i>j) return 0;
        int mini=INT_MAX;
        for(int ind=i;ind<=j;ind++){
           int cost=cuts[j+1]-cuts[i-1]+solve(i,ind-1,cuts)+solve(ind+1,j,cuts);
           mini=min(cost,mini);
        }
        return mini;
    }

    int topdown(int i,int j,vector<int>&cuts,vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=INT_MAX;
        for(int ind=i;ind<=j;ind++){
           int cost=cuts[j+1]-cuts[i-1]+topdown(i,ind-1,cuts,dp)+topdown(ind+1,j,cuts,dp);
           mini=min(cost,mini);
        }
        return dp[i][j]=mini;
    }

    int bottomup(int n,int c,vector<int>&cuts,vector<vector<int>>&dp){
       
        for(int i=c;i>=1;i--){
            for(int j=1;j<=c;j++){
                int mini=INT_MAX;
                if(i>j) continue;
                for(int ind=i;ind<=j;ind++){
                int cost=cuts[j+1]-cuts[i-1]+dp[i][ind-1]+dp[ind+1][j];
                mini=min(cost,mini);
                }
                dp[i][j]=mini;
            }
        }
        return dp[1][c];
    }

    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        // return solve(1,c,cuts);

        //top down dp
        // vector<vector<int>>dp(c+1,vector<int>(c+1,-1));
        // return topdown(1,c,cuts,dp);
        
        //bottom up dp
        vector<vector<int>>dp(c+2,vector<int>(c+2,0));
        return bottomup(n,c,cuts,dp);
    }
};