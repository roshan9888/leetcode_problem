class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //brute force
        // int maxi=0;
        // for(int i=0;i<nums.size();i++){
        //     int k1=k;
        //     for(int j=i;j<nums.size();j++){
        //         if(nums[j]==1){
        //             maxi=max(maxi,j-i+1);
        //         }
        //         else if(nums[j]==0 && k1>0){
        //             maxi=max(maxi,j-i+1);
        //             k1--;
        //         }
        //         else{
        //             break;
        //         }
        //     }
        // }
        // return maxi;

        //optimal solution
        // int i=0;
        // int j=0;
        // int maxi=0;
        // int zerocount=0;
        // while(j<nums.size()){
        //     if(nums[j]==1){
        //         maxi=max(maxi,j-i+1);
        //         j++;
        //     }
        //     else if(nums[j]==0){
        //         if(zerocount<k){
        //         maxi=max(maxi,j-i+1);
        //         j++;
        //         zerocount++;
        //         }
        //     }
        //     else{
        //         while(zerocount==k){
        //         if(nums[i]==0){
        //             zerocount--;
        //         }
        //         i++;
        //         }
        //     }
        // }
        // return maxi;
    int left = 0, right = 0;
    int maxOnes = 0;
    int zeroCount = 0;

    while (right < nums.size()) {
        if (nums[right] == 0) {
            zeroCount++;
        }

        while (zeroCount > k) {
            if (nums[left] == 0) {
                zeroCount--;
            }
            left++;
        }

        maxOnes = max(maxOnes, right - left + 1);
        right++;
    }

    return maxOnes;
    }
};