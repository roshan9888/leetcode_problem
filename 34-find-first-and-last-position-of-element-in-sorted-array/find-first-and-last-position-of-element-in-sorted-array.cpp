class Solution {
public:
    int binarysearchleft(vector<int>& nums,int low,int high,int target){
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }

    int  binarysearchright(vector<int>& nums,int low,int high,int target){
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]<=target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return high;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        int n=nums.size();
        int left=binarysearchleft(nums,0,n-1,target);
        int right=binarysearchright(nums,0,n-1,target);

        if(left<=right){
            ans.push_back(left);
            ans.push_back(right);
        }
        else{
            return {-1,-1};
        }
        return ans;
    }
};