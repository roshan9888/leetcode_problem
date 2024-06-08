class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //brute force
        vector<int>temp(nums.size(),0);
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                temp[j]=nums[i];
                j++;
            }
        }
        for(int i=0;i<temp.size();i++){
            nums[i]=temp[i];
        }
        
        // int left=0;
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     if(nums[i]!=0){
        //         nums[left]=nums[i];
        //         left++;
        //     }
        // }
        // while(left<n){
        //     nums[left]=0;
        //     left++;
        // }
    }
};