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

        //optimal solution
        int i=0;
        int maxsum=nums[i];
        int sum=0;
        vector<int>ans;
        while(i<nums.size()){
            sum+=nums[i];
            maxsum=max(sum,maxsum);
            if(sum<0){
                sum=0;
            }
            i++;
        }
        for(auto it:ans){
            cout<<it<<" ";
        }
        return maxsum;

        //for storing values 
        // vector<int>ans;
        // int i=0;
        // int maxsum=nums[i];
        // int sum=0;
        // int start=0;
        // int end=0;
        // int tempstart=0;
        // while(i<nums.size()){
        //     sum+=nums[i];
        //     if(sum>maxsum){
        //         maxsum=sum;
        //         start=tempstart;
        //         end=i;
        //     }
        //     if(sum<0){
        //         sum=0;
        //         tempstart=i+1;
        //     }
        //     i++;
        // }

        // for(int i=start;i<=end;i++){
        //     ans.push_back(nums[i]);
        // }
        // for(auto it:ans){
        //     cout<<it<<" ";
        // }
        // return maxsum;
    }
};