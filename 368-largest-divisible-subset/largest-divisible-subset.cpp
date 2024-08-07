class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,1),hash(n);
        sort(nums.begin(),nums.end());
        int lastindex=0,maxi=1;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if((nums[i]%nums[prev])==0 && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }

            if(dp[i]>maxi){
                maxi=dp[i];
                lastindex=i;
            }
        }

        vector<int>temp;
        temp.push_back(nums[lastindex]);
        while(hash[lastindex]!=lastindex){
            lastindex=hash[lastindex];
            temp.push_back(nums[lastindex]);
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};