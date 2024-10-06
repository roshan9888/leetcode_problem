class Solution {
public:
    long long int func(vector<int>&piles,int k){
        long long time=0;
        for(int i=0;i<piles.size();i++){
            time+=ceil((double)piles[i]/(double)(k));
        }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=INT_MIN;
        for(int i=0;i<piles.size();i++){
            maxi=max(maxi,piles[i]);
        }
        int low=1;
        int high=maxi;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;;

            long long int midn=func(piles,mid);
            if(midn<=h){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};