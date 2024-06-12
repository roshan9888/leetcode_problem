class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>pos;
        vector<int>neg;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                pos.push_back(nums[i]);
            }
            else{
            neg.push_back(nums[i]);
            }
        }

        vector<int>ans(n,0);
        for(int i=0;i<pos.size();i++){
            ans[2*i]=pos[i];
        }

        for(int i=0;i<neg.size();i++){
            ans[2*i+1]=neg[i];
        }
        return ans;
    }
};