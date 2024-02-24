class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //brute force
        // using two for loop
        // time complexity O(n^2)

        //better solution
        // if(nums.size()==0) return 0;
        // sort(nums.begin(),nums.end());
        // int count=0;
        // int longest=1;
        // int lastsmaller=INT_MIN;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]-1==lastsmaller){
        //         count++;
        //         lastsmaller=nums[i];
        //     }
        //     else if(nums[i]!=lastsmaller){
        //         count=1;
        //         lastsmaller=nums[i];
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
    }
};