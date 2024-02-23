class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        //brute force
        // int n=arr.size();
        // for(int i=0;i<n-1;i++){
        //      int maxi=INT_MIN;
        //     for(int j=i+1;j<n;j++){
        //        maxi=max(maxi,arr[j]);
        //     }
        //     arr[i]=maxi;
        // }
        // arr[n-1]=-1;
        // return arr;
        
        //time complexity O(n^2)

        //optimal solution
       
        int n=arr.size();
        int maxi=-1;
        for(int i=n-1;i>=0;i--){
            int newmaxi=max(maxi,arr[i]);
            arr[i]=maxi;
            maxi=newmaxi;
        }
        return arr;
    }
};