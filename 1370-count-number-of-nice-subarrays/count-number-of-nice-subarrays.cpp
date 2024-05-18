class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        //brute force
        // int count=0;
        // for(int i=0;i<nums.size();i++){
        //     int oddcount=0;
        //     for(int j=i;j<nums.size();j++){
        //         if(nums[j]%2!=0){
        //             oddcount++;
        //         }
        //         if(oddcount==k){
        //             count++;
        //         }
        //         else if(oddcount>k){
        //             break;
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
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                nums[i]=0;
            }
            else{
                nums[i]=1;
            }
        }
        for(auto it:nums){
            cout<<it<<" ";
        }
       while(j<nums.size()){
        sum+=nums[j];
        while(i<j && (nums[i]==0 || sum>k)){
            if(nums[i]==0){
                xeroes++;
            }
            else{
                xeroes=0;
            }
            sum-=nums[i];
            i++;
        }
        if(sum==k){
           count+=1+xeroes;
        }
        j++;
       }
       return count;
    }
};

