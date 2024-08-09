class Solution {
public: 
    bool isPresent(int x,vector<int>&nums){
        for(int i=0;i<nums.size();i++){
            if(nums[i]==x) return true;
        }
        return false;
    }
    int longestConsecutive(vector<int>& nums) {
        //brute force
        // using two for loop
        // if(nums.size()==0) return 0;
        // int longest=1;
        // for(int i=0;i<nums.size();i++){
        //     int x=nums[i];
        //     int cnt=1;
        //     while(isPresent(x+1,nums)==true){
        //         x=x+1;
        //         cnt++;
        //     }
        //     longest=max(longest,cnt);
        // }
        // return longest;
        // time complexity O(n^2)

        //better solution
        // if(nums.size()==0) return 0;
        // int longest=1;
        // int count=0;
        // sort(nums.begin(),nums.end());
        // int lsmaller=INT_MIN;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]-1==lsmaller){
        //         count++;
        //         lsmaller=nums[i];
        //     }
        //     else if(nums[i]!=lsmaller){
        //         count=1;
        //         lsmaller=nums[i];
        //     }
        //     longest=max(longest,count);
        // }
        // return longest;

        //optimal solution
        int n=nums.size();
        if(n==0) return 0;
        int longest=1;
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }

        for(auto it:st){
            if(st.find(it-1)==st.end()){
                int cnt=1;
                int x=it;
                while(st.find(x+1)!=st.end()){
                    x=x+1;
                    cnt++;
                }
                longest=max(longest,cnt);
            }
        }
        return longest;

        // time complexity O(n)
    }
};