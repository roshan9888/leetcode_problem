class Solution {
public:
    long long func(vector<int>& piles,int k){
        long long totaltime=0;
        for(int i=0;i<piles.size();i++){
            totaltime+=ceil((double)piles[i]/(double)(k));
        }
        
        return totaltime;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=INT_MIN;
        for(int i=0;i<piles.size();i++){
            maxi=max(maxi,piles[i]);
        }
        // cout<<maxi<<" ";
        int low=1;
        int high=maxi;
        while(low<=high){
            // int mid=low+(high-low)/2;
            int mid=(low+high)/2;

            long long  midN=func(piles,mid);
            if(midN<=h){
                 high=mid-1;
            }
            else{
                low=mid+1;  
            }
        }
        return low;
    }
};

