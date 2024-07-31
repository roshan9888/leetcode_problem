class Solution {
public:
    int solve(int ind,vector<int>&nums){
        if(ind==0) return nums[ind];
        if(ind<0) return 0;

        int pick=nums[ind]+solve(ind-2,nums);
        int notpick=solve(ind-1,nums);

        return max(pick,notpick);
    }
     
    int space(int ind,vector<int>&nums){
        if(ind==0) return nums[0];
        int prev=nums[0];
        int prev2,curr;
        for(int i=1;i<=ind;i++){
            int pick=nums[i];
            if(i>1) pick+=prev2;
            int notpick=prev;

            curr=max(pick,notpick);

            prev2=prev;
            prev=curr;
        }
        return curr;
    }

    int rob(vector<int>& nums) {
       int n=nums.size();
       if(n==1) return nums[0];
       vector<int>temp1,temp2;
       for(int i=0;i<n-1;i++){
        temp1.push_back(nums[i]);
       }
       for(int i=1;i<=n-1;i++){
        temp2.push_back(nums[i]);
       }
    //    return max(solve(temp1.size()-1,temp1),solve(temp2.size()-1,temp2)); 
        
        return max(space(temp1.size()-1,temp1),space(temp2.size()-1,temp2));
    }
};