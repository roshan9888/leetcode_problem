class Solution {
public:
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

        int i=0;
        int j=1;
        int sum=0;
        while(i<j && j<n){
            int mini=prices[i];
            int maxi=prices[j];
            if(mini<=maxi){
                sum=max(sum,maxi-mini);
                j++;
            }
            else if(i<j && mini>maxi){
                i=j;
                j++;
            }
        }
        return sum;
    }
};