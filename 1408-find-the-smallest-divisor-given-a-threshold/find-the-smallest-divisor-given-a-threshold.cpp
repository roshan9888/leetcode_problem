class Solution {
public:
    bool ispossible(vector<int>&nums,int div,int threshold){
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            cnt+=ceil((double)nums[i]/(double)(div));
        }
        return cnt<=threshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        //brute force
        // int maxi=INT_MIN;
        // for(int i=0;i<nums.size();i++){
        //     maxi=max(maxi,nums[i]);
        // }
        // for(int i=1;i<=maxi;i++){
        //     if(ispossible(nums,i,threshold)){
        //         return i;
        //     }
        // }
        // return -1;

        //optimal solution
        int low=1;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
        }
        int high=maxi;
        while(low<=high){
            int mid=(low+high)/2;
            if(ispossible(nums,mid,threshold)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};