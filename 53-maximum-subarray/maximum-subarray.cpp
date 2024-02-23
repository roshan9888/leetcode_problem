class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //brute force solution
        // int maxsum=INT_MIN;
        // for(int i=0;i<nums.size();i++){
        //     int sum=0;
        //     for(int j=i;j<nums.size();j++){
        //         sum+=nums[j];
        //         maxsum=max(maxsum,sum);
        //     }
        // }
        // return maxsum;

        //better solution
        int i=0;
        int maxsum=nums[i];
        int sum=0;
        while(i<nums.size()){
            sum+=nums[i];
            maxsum=max(sum,maxsum);
            if(sum<0){
                sum=0;
            }
            i++;
        }
        return maxsum;
    }
};