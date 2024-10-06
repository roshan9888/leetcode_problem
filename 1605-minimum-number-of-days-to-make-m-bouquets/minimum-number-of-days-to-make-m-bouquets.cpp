class Solution {
public:
    bool possible(vector<int>&bloomDay,int day,int k,int m){
        int bloomno=0;
        int cnt=0;
       for(int i=0;i<bloomDay.size();i++){
          if(bloomDay[i]<=day){
            cnt++;
          }
          else{
            bloomno+=cnt/k;
            cnt=0;
          }
       }
        bloomno+=cnt/k;
       return bloomno>=m;
    }

    // int func(vector<int>&bloomDay,int mid,int m,int k){
    //     long long bloom=0;
    //     for(int i=1;i<=bloomDay.size();i++){
    //         if(bloomDay[i]<=mid){
    //             bloom++;
    //         }else{
    //             bloomno=bloom/k;
    //             bloom=0;
    //         }
    //     }
    //     bloomno=bloom/k;

    //     if(bloomno>=m) return 2;
    //     return 1;
    // }
    int minDays(vector<int>& bloomDay, int m, int k) {
        //brute force
        // long long  val=1ll*m*1ll*k;
        // if(val>bloomDay.size()) return -1;
        // int mini=INT_MAX;
        // int maxi=INT_MIN;
        // for(int i=0;i<bloomDay.size();i++){
        //     maxi=max(maxi,bloomDay[i]);
        //     mini=min(mini,bloomDay[i]);
        // }
        // for(int i=mini;i<=maxi;i++){
        //     if(possible(bloomDay,i,k,m)){
        //         return i;
        //     }
        // }
        // return -1;

        //optimal solution
        long long  val=1ll*m*1ll*k;
        if(val>bloomDay.size()) return -1;
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int i=0;i<bloomDay.size();i++){
            maxi=max(maxi,bloomDay[i]);
            mini=min(mini,bloomDay[i]);
        }
        int low=mini;
        int high=maxi;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            // int m=func(bloomDay,mid,m,k);
            if(possible(bloomDay,mid,k,m)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};