class Solution {
public:
     int findDuplicate(vector<int>& nums) {
    //     sort(nums.begin(),nums.end());
    //      for(int i=0;i<nums.size();i++){
    //         if(nums[i]==nums[i+1]){
    //             // count=count+1;
    //             return nums[i];
    //         }
    // }
    // return -1;
    
    //second solution
    // int ans=-1;
    // for(int i=0;i<nums.size();i++){
    //     int index=abs(nums[i]);

    //     if(nums[index]<0){
    //         ans=index;
    //         break;
    //     }
    //     nums[index]*=-1;
    // }
    // return ans;

    //positiong method
    while(nums[0]!=nums[nums[0]]){
        swap(nums[0],nums[nums[0]]);
    }
    return nums[0];
    }
};