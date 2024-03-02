class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // vector<int>ans;
        // unordered_map<int,int>mp;
        // int maxi=INT_MIN;
        // for(int i=0;i<arr.size();i++){
        //     maxi=max(maxi,arr[i]);
        // }
        // for(int i=0;i<arr.size();i++){
        //     mp[arr[i]]++;
        // }
        
        // for(int i=1;i<=maxi;i++){
        //   if(!mp[i]){
        //       ans.push_back(i);
        //   }
        // }
        
        // for(auto it:ans){
        //     cout<<it<<" ";
        // }
        // return ans[k-1];

        unordered_map<int, bool> mp;
        for (int num : arr) {
            mp[num] = true;
        }
        
        int missingCount = 0;
        for (int i = 1; ; i++) {
            if (!mp[i]) {
                missingCount++;
                if (missingCount == k) {
                    return i;
                }
            }
        }
    }
};