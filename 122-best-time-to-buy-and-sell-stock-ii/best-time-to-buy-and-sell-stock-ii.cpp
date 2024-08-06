class Solution {
public:
    int solve(int ind,vector<int>&prices,bool buy){
        if(ind==prices.size()) return 0;
        long profit=0;
        if(buy){
           profit=max((-prices[ind]+solve(ind+1,prices,0)),(solve(ind+1,prices,1)));
        }else{
           profit=max((prices[ind]+solve(ind+1,prices,1)),(solve(ind+1,prices,0)));
        }
        return profit;
    }

    int topdown(int ind,vector<int>&prices,bool buy,vector<vector<int>>&dp){
        if(ind==prices.size()) return 0;
        long profit=0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy){
           profit=max((-prices[ind]+topdown(ind+1,prices,0,dp)),(topdown(ind+1,prices,1,dp)));
        }else{
           profit=max((prices[ind]+topdown(ind+1,prices,1,dp)),(topdown(ind+1,prices,0,dp)));
        }
        return dp[ind][buy]=profit;
    }

    int bottomup(int n,vector<int>&prices,int buy,vector<vector<int>>&dp){
        dp[n][0]=0;
        dp[n][1]=0;
        // if(ind==prices.size()) return 0;
        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                long profit=0;
                if(buy){
                    profit=max((-prices[ind]+dp[ind+1][0]),(dp[ind+1][1]));
                }else{
                    profit=max((prices[ind]+dp[ind+1][1]),(dp[ind+1][0]));
                }
                dp[ind][buy]=profit;
            }
        }
        return dp[0][1];
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
    //    return solve(0,prices,1);

    //top down dp
    // vector<vector<int>>dp(n,vector<int>(2,-1));
    // return topdown(0,prices,1,dp);
    
    //bottom up dp
    vector<vector<int>>dp(n+1,vector<int>(2,0));
    return bottomup(n,prices,1,dp);
    }
};