class Solution {
public:
    int jump(vector<int>& nums) {
        int lastjump=0;
        int count=0;
        int coverage=0;
        if(nums.size()==1) return 0;
        for(int i=0;i<nums.size();i++){
            coverage=max(coverage,i+nums[i]);
            
            if(i==lastjump){
                lastjump=coverage;
                count++;

                if(coverage>=nums.size()-1) return count;
            }
        }
        return count;
    }
};