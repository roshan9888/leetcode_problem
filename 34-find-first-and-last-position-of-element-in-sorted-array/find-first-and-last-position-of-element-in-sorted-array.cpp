class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //brute force
        // int i=0;
        // int fo=-1;
        // int lo=-1;
        // while(i<nums.size()){
        //     if(nums[i]==target){
        //         fo=i;
        //         lo=i;
        //         break;
        //     }
        //     i++;
        // }
        // while(i<nums.size()){
        //     if(nums[i]==target){
        //         lo=i;
        //     }
        //     i++;
        // }
        // return {fo,lo};
        
        int fo=-1,lo=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                if(fo==-1){
                    fo=i;
                }
                lo=i;
            }
        }
        return {fo,lo};

        //optimal solution

    }
};