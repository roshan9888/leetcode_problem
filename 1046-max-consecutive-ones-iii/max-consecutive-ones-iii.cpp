class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // int i=0;
        // int j=0;
        // int zeroes=0;
        // int sum=0;
        // while(j<nums.size()){
        //     if(nums[i]==0){
        //         zeroes++;
        //         k--;
        //         j++;
        //     }
        //     if(k<0){
        //         sum-=nums[i];
        //         if(nums[i]==0){
        //             zeroes--;
        //             k++;
        //         }
        //         i++;
        //     }
        //     if(zeroes<=k){
        //       sum+=nums[j];
        //        j++;
        //     }
        // }
        // return sum;

        int i = 0;
        int j = 0;
        int sum = 0;
        int maxLength = 0;

        while (j < nums.size()) {
            if (nums[j] == 0) {
                k--;
            }

            while (k < 0) {
                if (nums[i] == 0) {
                    k++;
                }
                i++;
            }

            sum = j - i + 1;
            maxLength = std::max(maxLength, sum);
            j++;
        }

        return maxLength;
    }
};