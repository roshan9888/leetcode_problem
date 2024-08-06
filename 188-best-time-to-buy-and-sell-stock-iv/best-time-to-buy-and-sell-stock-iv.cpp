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
     
    int bottomup(int n,vector<int>&prices,int buy,int k,vector<vector<vector<int>>>&dp){
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int count=1;count<=k;count++){
                    long profit=0;
                        if(buy){
                        dp[ind][buy][count]=max((-prices[ind]+dp[ind+1][0][count]),(dp[ind+1][1][count]));
                        }else{
                        dp[ind][buy][count]=max((prices[ind]+dp[ind+1][1][count-1]),(dp[ind+1][0][count]));
                        }
                    }
                }
            }
        return dp[0][1][k];    
    }

    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        // return solve(0,prices,1,k);

        //topdown dp
        // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        // return topdown(0,prices,1,k,dp);

        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        return bottomup(n,prices,1,k,dp);
    }
};