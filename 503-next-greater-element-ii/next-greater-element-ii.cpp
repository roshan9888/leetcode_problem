class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>ans(nums.size(),-1);
        for(int i=0;i<nums.size();i++){
            int a=nums[i];
            for(int j=i+1;j<i+2*nums.size();j++){
                if(nums[j%nums.size()]>a){
                    ans[i]=nums[j%nums.size()];
                    break;
                }
            }
        }
        return ans;
    }
};