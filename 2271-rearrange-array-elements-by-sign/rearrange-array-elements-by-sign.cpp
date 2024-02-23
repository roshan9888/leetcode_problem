class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        //brute force
        // vector<int>pos;
        // vector<int>neg;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]>0){
        //         pos.push_back(nums[i]);
        //     }
            //    else{
        //         neg.push_back(nums[i]);
        //     }
        // }
        // int n=nums.size()/2;
        // for(int i=0;i<n;i++){
        //     nums[i*2]=pos[i];
        //     nums[i*2+1]=neg[i];
        // }
        // return nums;

        //optimal solution
        int n=nums.size();
        vector<int>ans(n,0);
        int neg=1;
        int pos=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                ans[pos]=nums[i];
                pos+=2;
            }
            else{
                ans[neg]=nums[i];
                neg+=2;
            }
        }
        return ans;

        //follow up question if positive are more the negative
        //if negatives are more then postive
    }
};