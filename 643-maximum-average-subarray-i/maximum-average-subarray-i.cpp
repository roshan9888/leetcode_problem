class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        double sum=0;
        double maxAverage = numeric_limits<double>::lowest();
        while(j<nums.size()){
            sum+=nums[j];
            if(j-i+1==k){
               maxAverage=max(maxAverage,sum/k);
               sum-=nums[i];
               i++;
            }
            j++;
        }
        return maxAverage;
    }
};