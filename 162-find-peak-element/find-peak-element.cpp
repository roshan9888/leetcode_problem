class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(nums.size()==2){
            if(nums[1]>nums[0]){
                return 1;
            }
        }
        // int n = nums.size();
        if (n == 1) return 0; // If there's only one element, it's a peak.

        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                return i; // Peak found.
            }
        }
        // Check if the first or last element is a peak.
        if (nums[0] > nums[1]) return 0; // Peak at the beginning.
        if (nums[n - 1] > nums[n - 2]) return n - 1; // Peak at the end.
        
        return -1; // No peak found.
    }
};