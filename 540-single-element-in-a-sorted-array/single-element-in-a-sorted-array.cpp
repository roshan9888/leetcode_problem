class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //brute force
        // int ans=0;
        // for(int i=0;i<nums.size();i++){
        //     ans=ans^nums[i];
        // }
        // return ans;

        //optimal solution
        int n=nums.size();
        int low=1;
        int high=nums.size()-2;
        if(nums.size()==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) return nums[mid];
            if(mid%2==0){
               if(nums[mid]!=nums[mid+1]){
                   high=mid-1;
               }
               else{
                   low=mid+1;
               }
            }
            else{
               if(nums[mid]!=nums[mid-1]){
                  high=mid-1;
               }
               else{
                   low=mid+1;
               }
            }
        }
        return -1;
    }
};