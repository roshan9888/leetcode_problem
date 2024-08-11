class Solution {
public: 
    int lowerbound(vector<int>& nums,int low,int high,int target){
        int ans=nums.size();
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>=target){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }

    int  upperbound(vector<int>& nums,int low,int high,int target){
        int ans=nums.size();
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>target){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        //brute force
        // int i=0;
        // int fo=-1;
        // int lo=-1;
        // while(i<nums.size()){
        //     if(nums[i]==target){
        //         fo=i;
        //         lo=i;
        //         break;
        //     }
        //     i++;
        // }
        // while(i<nums.size()){
        //     if(nums[i]==target){
        //         lo=i;
        //     }
        //     i++;
        // }
        // return {fo,lo};
        
        // int fo=-1,lo=-1;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==target){
        //         if(fo==-1){
        //             fo=i;
        //         }
        //         lo=i;
        //     }
        // }
        // return {fo,lo};

        //optimal solution
        int n=nums.size();
        int left=lowerbound(nums,0,n-1,target);
        int right=upperbound(nums,0,n-1,target);
        cout<<left<<" ";
        cout<<right<<" ";
        if(left==n || nums[left]!=target) return {-1,-1};
        return {left,right-1};
    }
};