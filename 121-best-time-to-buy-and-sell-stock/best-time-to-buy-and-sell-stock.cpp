class Solution {
public:
    void solve(vector<int>& prices,int i,int &min_p,int &max_p){
        if(i==prices.size()) return;

        if(prices[i]<min_p){
            min_p=prices[i];
        }

        if((prices[i]-min_p)>max_p){
            max_p=prices[i]-min_p;
        }

        solve(prices,i+1,min_p,max_p);
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();

        if(n<2) return 0;
        // int maxp=0;
        // for(int i=0;i<n;i++){
        //     int profit=0;
        //     for(int j=i+1;j<n;j++){
        //         if(prices[j]>prices[i]){
        //             profit=prices[j]-prices[i];
        //         }
        //         maxp=max(maxp,profit);
        //     }
        // }
        // return maxp;
        
        //iterative approach
        // int i=0;
        // int j=1;
        // int sum=0;
        // while(i<j && j<n){
        //     int mini=prices[i];
        //     int maxi=prices[j];
        //     if(mini<=maxi){
        //         sum=max(sum,maxi-mini);
        //         j++;
        //     }
        //     else if(i<j && mini>maxi){
        //         i=j;
        //         j++;
        //     }
        // }
        // return sum;

        //recursive approach
        int max_profit=INT_MIN;
        int min_price=INT_MAX;
        solve(prices,0,min_price,max_profit);
        return max_profit;
    }
};