class Solution {
public:
    int solve(int ind,vector<int>&prices,bool buy,int fee){
        if(ind==prices.size()) return 0;
        long profit=0;
        if(buy){
           profit=max((-prices[ind]+solve(ind+1,prices,0,fee)),(solve(ind+1,prices,1,fee)));
        }else{
           profit=max(((prices[ind]-fee)+solve(ind+1,prices,1,fee)),(solve(ind+1,prices,0,fee)));
        }
        return profit;
    }
    
    int topdown(int ind,vector<int>&prices,int buy,vector<vector<int>>&dp,int fee){
        if(ind==prices.size()) return 0;
        long profit=0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy){
           profit=max((-prices[ind]+topdown(ind+1,prices,0,dp,fee)),(topdown(ind+1,prices,1,dp,fee)));
        }else{
           profit=max((prices[ind]-fee+topdown(ind+1,prices,1,dp,fee)),(topdown(ind+1,prices,0,dp,fee)));
        }
        return dp[ind][buy]=profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        // return solve(0,prices,1,fee);

        //topdown dp
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return topdown(0,prices,1,dp,fee);
    }
};