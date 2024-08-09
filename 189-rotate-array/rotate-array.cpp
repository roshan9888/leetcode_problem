class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //brute force O(kn)
        // int n=nums.size();
        // int k1=k%n;
        // while(k1){
        //     int temp=nums[n-1];
        //     for(int i=n-1;i>-0;i--){
        //         nums[i]=nums[i-1];
        //     }
        //     nums[0]=temp;
        //     k1--;
        // }

        //optimal solution
        int n=nums.size();
        k=k%n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};