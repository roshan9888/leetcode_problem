class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // int numsum=0,totsum=0;
        // for(int i=0;i<nums.size();i++){
        //     numsum+=nums[i];
        // }
        // for(int i=1;i<=nums.size();i++){
        //      totsum+=i;
        // }
        // return totsum-numsum;

        int xorarr=0;
        int xorall=0;
        for(int i=1;i<=nums.size();i++){
            xorall^=i;
        }

        for(int i=0;i<nums.size();i++){
            xorarr^=nums[i];
        }
        return xorall^xorarr;
    }
};