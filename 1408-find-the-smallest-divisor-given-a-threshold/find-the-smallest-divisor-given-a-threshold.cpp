class Solution {
public:
    long long func(vector<int>&nums,int mid){
        int thre=0;
        for(int i=0;i<nums.size();i++){
            thre+=ceil(ceil(nums[i])/ceil(mid));
            // cout<<thre<<" ";
        }
        // cout<<thre<<" ";
        return thre;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int mini=1;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            // mini=min(mini,nums[i]);
            maxi=max(maxi,nums[i]);
        }
        int low=mini;
        int high=maxi;
        while(low<=high){
            int mid=(low+high)/2;
            long long midn=func(nums,mid);
            if(midn>threshold){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};