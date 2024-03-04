class Solution {
public:
     bool search(vector<int>&nums,int target,int m){
       int low=0;
       int high=m-1;
       cout<<m<<" ";
       while(low<=high){
           int mid=(low+high)/2;
            if(nums[mid]==target) return true;
           if(nums[mid]>target){
               high=mid-1;
           }
           else{
               low=mid+1;
           }
       }
       return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // int n=matrix.size();
        // int m=matrix[0].size();
        // bool ans;
        // for(int i=0;i<n;i++){
        //     ans=search(matrix[i],target,m);
        //     if(ans){
        //         return ans;
        //     }
        // }
        // return ans;

        int n = matrix.size();
        int m = matrix[0].size();

        int rows = 0 , cols = m - 1;

        while(rows < n && cols >= 0){
            if(matrix[rows][cols] == target){
                return true;
            }else if(target > matrix[rows][cols]){
                rows++ ;
            }else{
                cols--;
            }
        }

        return false;
    }
};