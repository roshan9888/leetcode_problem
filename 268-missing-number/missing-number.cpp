class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int ts=0;
        for(int i=0;i<=n;i++){
            ts+=i;
        }
        int nsum=0;
        for(int i=0;i<n;i++){
            nsum+=nums[i];
        }
        return ts-nsum;
    }
};