class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        
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