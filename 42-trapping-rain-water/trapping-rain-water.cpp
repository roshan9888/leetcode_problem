class Solution {
public:
    int trap(vector<int>& height) {
        //brute force O(n2)
        // int watertrapped=0;
        // int n=height.size();
        // for(int i=0;i<n;i++){
        //     int j=i;
        //     int leftmax=0,rightmax=0;
        //     while(j>=0){
        //         leftmax=max(leftmax,height[j]);
        //         j--;
        //     }
        //     j=i;
        //     while(j<n){
        //         rightmax=max(rightmax,height[j]);
        //         j++;
        //     }
        //     watertrapped+=min(leftmax,rightmax)-height[i];
        // }
        // return watertrapped;

        //better solution 
        int watertrapped=0;
        int n=height.size();
        vector<int>prefix(n);
        vector<int>suffix(n);
        prefix[0]=height[0];
        for(int i=1;i<n;i++){
          prefix[i]=max(prefix[i-1],height[i]);
        }
        suffix[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]=max(suffix[i+1],height[i]);
        }

        for(int i=0;i<n;i++){
            watertrapped+=min(prefix[i],suffix[i])-height[i];
        }
        return watertrapped;
    }
};