class Solution {
public:
    int solve(int ind,vector<int>&prices,bool buy,int count){
        if(count==0) return 0;
        if(ind==prices.size()) return 0;
        long profit=0;
        if(buy){
           profit=max((-prices[ind]+solve(ind+1,prices,0,count)),(solve(ind+1,prices,1,count)));
        }else{
           profit=max((prices[ind]+solve(ind+1,prices,1,count-1)),(solve(ind+1,prices,0,count)));
        }
        return profit;
    }
    
    int topdown(int ind,vector<int>&prices,int buy,int count,vector<vector<vector<int>>>&dp){
        if(ind==prices.size() || count==0) return 0;
        // if() return 0;
        if(dp[ind][buy][count]!=-1) return dp[ind][buy][count];
        long profit=0;
        if(buy){
           profit=max((-prices[ind]+topdown(ind+1,prices,0,count,dp)),(topdown(ind+1,prices,1,count,dp)));
        }else{
           profit=max((prices[ind]+topdown(ind+1,prices,1,count-1,dp)),(topdown(ind+1,prices,0,count,dp)));
        }
        return dp[ind][buy][count]=profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        // return solve(0,prices,1,k);

        //topdown dp
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return topdown(0,prices,1,k,dp);


    }
};