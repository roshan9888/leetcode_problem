class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //brute force
        // int n=nums1.size();
        // int m=nums2.size();
        // vector<int>temp;
        // int i=0,j=0;
        // while(i<n && j<m){
        //     if(nums1[i]<nums2[j]){
        //         temp.push_back(nums1[i++]);
        //     }
        //     else{
        //         temp.push_back(nums2[j++]);
        //     }
        // }

        // while(i<n){
        //     temp.push_back(nums1[i++]);   
        // }

        // while(j<m){
        //     temp.push_back(nums2[j++]);
        // }

        // int t=temp.size();
        // if(t%2){
        //    return temp[t/2];
        // }
        // return (temp[t / 2] + temp[t / 2 - 1]) / 2.0;

        //better solution
        // int i=0;
        // int j=0;
        // int n=nums1.size()+nums2.size();
        // int ind2=n/2;
        // int ind1=ind2-1;
        // int cnt=0;
        // int ind1el=-1;
        // int ind2el=-1;
        // while(i<nums1.size() && j<nums2.size()){
        //     if(nums1[i]<nums2[j]){
        //         if(cnt==ind1) ind1el=nums1[i];
        //         if(cnt==ind2) ind2el=nums1[i];
        //         cnt++;
        //         i++;
        //     }
        //     else{
        //         if(cnt==ind1) ind1el=nums2[j];
        //         if(cnt==ind2) ind2el=nums2[j];
        //         cnt++;
        //         j++;
        //     }
        // }

        // while(i<nums1.size()){
        //     if(cnt==ind1) ind1el=nums1[i];
        //     if(cnt==ind2) ind2el=nums1[i];
        //     cnt++;
        //     i++;
        // }

        // while(j<nums2.size()){
        //     if(cnt==ind1) ind1el=nums2[j];
        //     if(cnt==ind2) ind2el=nums2[j];
        //     cnt++;
        //     j++;
        // }

        // if(n%2){
        //     return (double)ind2el;
        // }

        // return ((double)ind1el+(double)ind2el)/2.0;


        //optimal solution
        int n1=nums1.size();
        int n2=nums2.size();
        if(n1>n2) return findMedianSortedArrays(nums2,nums1);
        int low=0;
        int high=n1;
        int left=(n1+n2+1)/2;
        int n=n1+n2;
        while(low<=high){
            int mid1=(low+high)/2;
            int mid2=left-mid1;
            int l1=INT_MIN;
            int l2=INT_MIN;
            int r1=INT_MAX,r2=INT_MAX;
            if(mid1<n1) r1=nums1[mid1];
            if(mid2<n2) r2=nums2[mid2];
            if(mid1-1>=0) l1=nums1[mid1-1];
            if(mid2-1>=0) l2=nums2[mid2-1];

            if(l1<=r2 && l2<=r1){
                if(n%2) return max(l1,l2);
                return (double)(max(l1,l2)+min(r1,r2))/2.0;
            }
            else if(l1>r2){
                high=mid1-1;
            }
            else{
                low=mid1+1;
            }
        }
        return 0;
    }
};