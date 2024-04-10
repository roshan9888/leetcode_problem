class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        threshold*=k;
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=arr[i];
        }
        int ans=0;
        if(sum>=threshold)ans++;
        int n=arr.size();
        for(int i=1;i<=n-k;i++){
            sum-=arr[i-1];
            sum+=arr[i+k-1];
            if(sum>=threshold)ans++;
        }
        return ans;
    }
};