class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        for(int i=0;i<n-1;i++){
             int maxi=INT_MIN;
            // int num=arr[i];
            for(int j=i+1;j<n;j++){
               maxi=max(maxi,arr[j]);
            }
            arr[i]=maxi;
        }
        arr[n-1]=-1;
        return arr;
    }
};