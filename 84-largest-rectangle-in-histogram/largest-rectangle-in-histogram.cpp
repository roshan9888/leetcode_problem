class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        //brute force
        // int n=height.size();
        // int maxrec=INT_MIN;
        // for(int i=0;i<n;i++){
        //     int j=i;
        //     int leftcount=0,rightcount=0;
        //     while(j>=0){
        //         if(height[j]<height[i]){
        //             break;
        //         }
        //         else{
        //             leftcount++;
        //         }
        //         j--;
        //     }
        //     j=i+1;
        //     while(j<n){
        //         if(height[j]<height[i]){
        //             break;
        //         }
        //         else{
        //         rightcount++;
        //         }
        //         j++;
        //     }
        //     maxrec=max(maxrec,(leftcount+rightcount)*height[i]);
        // }
        // return maxrec;

        //optimal solution O(n)
        int n=height.size();
        vector<int>left(n);
        vector<int>right(n);
        stack<int>s;
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            while(!s.empty() && height[s.top()]>=height[i]){
                s.pop();
            }
            if(s.empty()) left[i]=0;
            else left[i]=s.top()+1;
            s.push(i);
        }

        //clear the stack for reuse
        while(!s.empty()) s.pop();

        for(int i=n-1;i>=0;i--){
            while(!s.empty() && height[s.top()]>=height[i]){
                s.pop();
            }
            if(s.empty()) right[i]=n-1;
            else right[i]=s.top()-1;
            s.push(i);

            ans=max(ans,(right[i]-left[i]+1)*height[i]);
        }
        // int ans=INT_MIN;
        // for(int i=0;i<n;i++){
        //     ans=max(ans,(right[i]-left[i]+1)*height[i]);
        // }
        return ans;
    }
};