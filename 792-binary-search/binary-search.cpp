class Solution {
public:
    int binarysearch(vector<int>&nums,int low,int high,int target){
        while(low<=high){
        int mid=low+(high-low)/2;
           if(nums[mid]==target) return mid;

        if(nums[mid]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
        }
        
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n=nums.size();
        return binarysearch(nums,0,n-1,target);
    }
};