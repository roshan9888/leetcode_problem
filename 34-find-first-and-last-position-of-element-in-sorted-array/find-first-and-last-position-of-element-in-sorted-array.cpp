class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int i=0;
        int fo=-1;
        int lo=-1;
        while(i<nums.size()){
            if(nums[i]==target){
                fo=i;
                lo=i;
                break;
            }
            i++;
        }
        while(i<nums.size()){
            if(nums[i]==target){
                lo=i;
            }
            i++;
        }
        return {fo,lo};
    }
};