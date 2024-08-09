class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        //brute force
        // int n=nums.size();
        // vector<int>pos;
        // vector<int>neg;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]>0){
        //         pos.push_back(nums[i]);
        //     }
        //     else{
        //     neg.push_back(nums[i]);
        //     }
        // }

        // vector<int>ans(n,0);
        // for(int i=0;i<pos.size();i++){
        //     ans[2*i]=pos[i];
        // }

        // for(int i=0;i<neg.size();i++){
        //     ans[2*i+1]=neg[i];
        // }
        // return ans;

        //better
        vector<int>ans(nums.size(),0);
        int pos=0;
        int neg=1;
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
    }
};