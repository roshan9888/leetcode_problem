class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // brute force 
        // vector<vector<int>>ans;
        // sort(nums.begin(),nums.end());
        // set<vector<int>>set;
        // for(int i=0;i<nums.size()-2;i++){
        //     for(int j=i+1;j<nums.size()-1;j++){
        //         for(int k=j+1;k<nums.size();k++){
        //             if(nums[i]+nums[j]+nums[k]==0 && i!=j && i!=k && j!=k){
        //                set.insert({nums[i],nums[j],nums[k]});
        //             }
        //         }
        //     }
        // f}
        // for(auto it:set){
        //     ans.push_back(it);
        // }
        // return ans;

        // time complexity O(n^3)

        //better solution
        // int n=nums.size();
        // set<vector<int>>st;
        // for(int i=0;i<n;i++){
        //     set<int>hashset;
        //     for(int j=i+1;j<n;j++){
        //         int third=-(nums[i]+nums[j]);
        //         if(hashset.find(third)!=hashset.end()){
        //             vector<int>temp={nums[i],nums[j],third};
        //             sort(temp.begin(),temp.end());
        //             st.insert(temp);
        //         }
        //         hashset.insert(nums[j]);
        //     }
        // }
        // vector<vector<int>>ans(st.begin(),st.end());
        // return ans;

        //optimal solution
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1;
            int k=nums.size()-1;

            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<0){
                   j++;
                }
                else if(sum>0){
                    k--;
                }
                else{
                   vector<int>temp={nums[i],nums[j],nums[k]};
                   ans.push_back(temp);
                   j++;
                   k--;
                   while(j<k && nums[j]==nums[j-1]) j++;
                   while(j<k && nums[k]==nums[k+1]) k--; 
                }
            }
        }
        return ans;
    }
};