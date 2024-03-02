class Solution {
public:
    int func(vector<int>& bloomDay,int mid,int k,int m){
        int count=0;
        int nofb=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                count++;
            }
            else{
                nofb+=(count/k);
                count=0;
            }
        }
        nofb+=(count/k);
        cout<<count<<" ";
        return nofb>=m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        int mini=INT_MAX;
        int maxi=INT_MIN;
        long long target=m*1LL*k*1LL;
        if(target>n) return -1;
        for(int i=0;i<n;i++){
            mini=min(mini,bloomDay[i]);
            maxi=max(maxi,bloomDay[i]);
        }
        int low=mini;
        int high=maxi;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(func(bloomDay,mid,k,m)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};