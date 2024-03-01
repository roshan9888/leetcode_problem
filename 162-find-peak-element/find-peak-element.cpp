class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        //brute force
        // int n=nums.size();
        // if (n == 1) return 0;

        // for (int i = 1; i < n - 1; i++) {
        //     if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
        //         return i;
        //     }
        // }
        // if (nums[0] > nums[1]) return 0; 
        // if (nums[n - 1] > nums[n - 2]) return n - 1;
        
        // return -1; 

        //optimal solution
        int n=nums.size();
        if(nums.size()==1) return 0;
        int low=1;
        int high=n-1;
        if (nums[0] > nums[1]) return 0; 
        if (nums[n - 1] > nums[n - 2]) return n - 1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid;
            }
            if(nums[mid]>nums[mid-1] && nums[mid]<nums[mid+1]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return -1;
    }
};