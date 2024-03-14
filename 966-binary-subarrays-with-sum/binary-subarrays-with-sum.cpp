class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            int s=nums[i];
            if(s==goal){
                count++;
            }
            for(int j=i+1;j<nums.size();j++){
                s=s+nums[j];
                if(s==goal){
                   count++;
                }
            }
        }
        return count;
    }
};