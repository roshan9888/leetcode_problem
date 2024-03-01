class Solution {
public:
int pivot(vector<int> arr){
    int s=0;
    int e=arr.size()-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(s==e){
            return s;
        }
        if(mid+1<=e && arr[mid]>arr[mid+1]){
            return mid;
        }
        if(mid-1>=s && arr[mid-1]>arr[mid]){
            return mid-1;
        }
        if(arr[s]>arr[mid]){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return -1;
}
  int binarysearch(vector<int> arr,int start,int end,int target){
    int mid = start+(end-start) / 2;
    while (start <= end)
    {
    int element=arr[mid];
        if (target == element)
        {
            return mid;
        }
        else if(target<element){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
         
        mid = start+(end-start) / 2;
    }
    return -1;
  }
    int search(vector<int>& nums, int target) {
        int pivotindex=pivot(nums);
        int ans=0;
        if(target>=nums[0] && target<=nums[pivotindex]){
            ans=binarysearch(nums,0,pivotindex,target);
        }
        else{
            ans=binarysearch(nums,pivotindex+1,nums.size()-1,target);
        }
        return ans;
    }
};