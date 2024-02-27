class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        //brute force
        // int count=0;
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i;j<nums.size();j++){
        //         int x=0;
        //         for(int k=i;k<=j;k++){
        //             x=x^nums[k];
        //         }
        //         if(x==0){
        //         count++;
        //         }
        //     }
        // }
        // return count;

        //time complexity O(n^3)


        //better solution
        // int count =0;
        // for(int i=0;i<nums.size();i++){
        //     int x1=0;
        //     for(int j=i;j<nums.size();j++){
        //         x1=x1^nums[j];
        //         if(x1==0){
        //             count++;
        //         }
        //     }
        // }
        // return count;  

        //time complexity O(n^2)


        //optimal solution
        map<int,int>mp;
        int k=0;
        mp[0]=1;
        long long cnt=0;
        long long xr=0;
        for(int i=0;i<nums.size();i++){
            xr=xr^nums[i];
            long remove=xr^k;
               cnt+=mp[remove];
               mp[xr]+=1;
              
        }
        return cnt;
    }
};