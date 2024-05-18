class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //brute force
        // int count=0;
        // for(int i=0;i<nums.size();i++){
        //     long long sum=0;
        //     for(int j=i;j<nums.size();j++){
        //         sum+=nums[j];
        //         if(sum==goal){
        //             count++;
        //         }
        //     }
        // }
        // return count;

        //optimal solution
        int i=0;
        int j=0;
        int count=0;
        int sum=0;
        int xeroes=0;
       while(j<nums.size()){
        sum+=nums[j];
        while(i<j && (nums[i]==0 || sum>goal)){
            if(nums[i]==0){
                xeroes++;
            }
            else{
                xeroes=0;
            }
            sum-=nums[i];
            i++;
        }
        if(sum==goal){
           count+=1+xeroes;
        }
        j++;
       }
       return count;
    }
};