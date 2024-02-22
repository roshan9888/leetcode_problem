class Solution {
public:
    void sortColors(vector<int>& nums) {
        //brute force solution
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         if(nums[i]>nums[j]){
        //             swap(nums[i],nums[j]);
        //         }
        //     }
        // }
        int zeroes=0;
        int ones=0;
        int twos=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                ones++;
            }
            else if(nums[i]==2){
                twos++;
            }
            else{
                zeroes++;
            }   
        }
        for(int i=0;i<zeroes;i++){
            nums[i]=0;
        }
        for(int i=zeroes;i<zeroes+ones;i++){
            nums[i]=1;
        }
        for(int i=zeroes+ones;i<nums.size();i++){
            nums[i]=2;
        }
    }
};