class Solution {
public:
    int solve(vector<int>& nums, int k){
        int l=0;
        int r=0;
        int n=nums.size();
        unordered_map<int,int>mp;
        int count=0;
        while(r<n){
            mp[nums[r]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0) mp.erase(nums[l]);
                l++;
            }
            count+=r-l+1;
            r++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        //brute force
        // int count=0;
        // unordered_map<int,int>mp;
        // for(int i=0;i<nums.size();i++){
        //     mp.clear();
        //     for(int j=i;j<nums.size();j++){
        //         mp[nums[j]]++;
        //         if(mp.size()==k){
        //             count++;
        //         }else if(mp.size()>k){
        //             break;
        //         }
        //     }
        // }
        // return count;

        //optimal solution
        return solve(nums,k)-solve(nums,k-1);
    }
};