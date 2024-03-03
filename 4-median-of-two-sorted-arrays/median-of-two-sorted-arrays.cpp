class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        int i=m-1;
        int j=n-1;
        int k=m+n-1;
        // int n1=nums1.size();
        // int n2=nums2.size();
        nums1.resize(m+n);
        while(j>=0){
            if(i>=0 && nums1[i]>nums2[j]){
                nums1[k--]=nums1[i--];
            }
            else{
                nums1[k--]=nums2[j--];
            }
        }
        for(auto it:nums1){
            cout<<it<<" ";
        }
        int low=0;
        int high=nums1.size()-1;
        if(nums1.size()%2==0){
            int mid1=(low+high)/2;
            int mid2=mid1+1;

            return double(nums1[mid1]+nums1[mid2])/2.0;
        }
        else{
             int mid1=(low+high)/2;
             return double(nums1[mid1]);
        }
        return 0;
    }
};