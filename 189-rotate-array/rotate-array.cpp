class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // int n=nums.size();
        // int k1=k%n;
        // while(k1){
        //     int temp=nums[n-1];
        //     for(int i=n-1;i>0;i--){
        //         nums[i]=nums[i-1];
        //     }
        //     nums[0]=temp;
        //     k1--;
        // }

        // int n=nums.size();
        // int k1=k%n;
        // while(k1){
        //     int temp=nums[n-1];
        //     for(int i=n-1;i>0;i--){
        //        nums[i]=nums[i-1]; 
        //     }
        //     nums[0]=temp;
        //     k1--;
        // }

        k=k%nums.size();
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};