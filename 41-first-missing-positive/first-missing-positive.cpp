class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int>mp;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto it:mp){
            cout<<it.first<<" "<<it.second<<endl;
        }
        long long n=abs(nums[nums.size()-1]);
        for(int i=1;i<=n+1;i++){
            if(mp.find(i)==mp.end()){
                return i;
            }
        }
        return 0;
    }
};