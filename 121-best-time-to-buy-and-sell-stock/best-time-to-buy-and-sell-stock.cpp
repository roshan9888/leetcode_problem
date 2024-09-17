class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int cost=prices[0];
        int maxprofit=INT_MIN;
        for(int i=0;i<prices.size();i++){
            int profit=prices[i]-cost;
            maxprofit=max(maxprofit,profit);
            cost=min(cost,prices[i]);
        }
        return maxprofit;
    }
};