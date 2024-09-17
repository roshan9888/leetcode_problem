class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //brute force solution
        // int n=nums.size();
        // int m=floor(n/2);
        // cout<<m<<" ";
        // for(int i=0;i<n;i++){
        //     int count=0;
        //     int occur=nums[i];
        //     for(int j=0;j<n;j++){
        //         if(nums[j]==occur){
        //             count++;
        //         }
        //     }
        //     if(count>m){
        //         cout<<count<<" ";
        //         return occur;
        //     }
        // }
        // return -1;

        //better solution
        // int n=nums.size();
        // int m=floor(n/2);
        // map<int,int>mp;
        // for(int i=0;i<n;i++){
        //     mp[nums[i]]++;
        // }

        // for(auto it:mp){
        //     if(it.second>m){
        //         return it.first;
        //     }
        // }
        // return -1;

        //optimal solution
        int count=0;
        int ele;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                ele=nums[i];
                count++;
            }
            else if(nums[i]==ele){
                count++;
            }
            else{
                count--;
            }
        }
        return ele;
    }
};