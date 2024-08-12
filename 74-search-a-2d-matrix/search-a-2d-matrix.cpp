class Solution {
public:
    bool find(vector<int>&arr,int target,int m){
        int low=0;
        int high=m-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]==target) return true;

            if(arr[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        bool ans=false;
        for(int i=0;i<n;i++){
            if(find(matrix[i],target,m)){
                return true;
            }
        }
        return false;
    }
};