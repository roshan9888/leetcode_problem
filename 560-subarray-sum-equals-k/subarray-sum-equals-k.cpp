class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        for(int i=0;i<nums.size();i++){   
            int sum=0;  
            // k=k-nums[i];
            for(int j=i;j<nums.size();j++){
                // k=k-nums[j];
                sum+=nums[j];
                if(sum==k){
                    count++;
                    // break;
                }
            }
        }
        return count;
    }
};

// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int count = 0;
//         int n = nums.size();
//         for (int start = 0; start < n; ++start) {
//             int sum = 0;
//             for (int end = start; end < n; ++end) {
//                 sum += nums[end];
//                 if (sum == k) {
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };
