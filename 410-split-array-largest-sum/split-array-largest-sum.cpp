class Solution {
public:
    int func(vector<int>&weights,int mid){
        int capacity=0;
        int count=1;
        for(int i=0;i<weights.size();i++){
            if(capacity+weights[i]>mid){
               cout<<count<<" ";
               count++;
               capacity=weights[i];
            }
            else{
                capacity+=weights[i];
            }
        }
        return count;
    }
    int splitArray(vector<int>& weights, int days) {
        int sum=0;
        int maxi=INT_MIN;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
            maxi=max(maxi,weights[i]);
        }
        int low=maxi;
        int high=sum;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;

            int midn=func(weights,mid);
            // if(midn==days) return mid;
            
            if(midn<=days){
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