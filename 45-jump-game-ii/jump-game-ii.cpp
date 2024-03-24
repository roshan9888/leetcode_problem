class Solution {
public:
    int jump(vector<int>& nums) {
        int totaljmp=0;
        int coverage=0,lastjmp=0;

        if(nums.size()==1) return 0;

        for(int i=0;i<nums.size();i++){
            coverage=max(coverage,i+nums[i]);

            if(i==lastjmp){
                lastjmp=coverage;
                totaljmp++;

                if(coverage>=nums.size()-1){
                    return totaljmp;
                }
            }
        }
        return totaljmp;
    }
};