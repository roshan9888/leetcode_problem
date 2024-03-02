class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // unordered_map<int, bool> mp;
        // for (int num : arr) {
        //     mp[num] = true;
        // }
        // int missingCount = 0;
        // for (int i = 1; ; i++) {
        //     if (!mp[i]) {
        //         missingCount++;
        //         if (missingCount == k) {
        //             return i;
        //         }
        //     }
        // }

        //brute force
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=k) k++;
            else{
                break;
            }
        }
        return k;
        // bool func(vector<int>arr,int mid){
            
        // }
        //  int maxi=INT_MIN;
        //  for(int i=0;i<arr.size();i++){
        //      maxi=max(maxi,arr[i]);
        //  }
        // int low=1;
        // int high=maxi;
        // while(low<=high){
        //     int mid=low+(high-low)/2;

        //     int midN=func(arr,mid);
        // }

    }
};