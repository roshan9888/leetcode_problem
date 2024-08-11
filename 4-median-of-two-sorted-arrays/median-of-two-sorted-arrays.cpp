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

        //optimal solution
        int i=0;
        int j=0;
        int n=nums1.size()+nums2.size();
        int ind2=n/2;
        int ind1=ind2-1;
        int cnt=0;
        int ind1el=-1;
        int ind2el=-1;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]){
                if(cnt==ind1) ind1el=nums1[i];
                if(cnt==ind2) ind2el=nums1[i];
                cnt++;
                i++;
            }
            else{
                if(cnt==ind1) ind1el=nums2[j];
                if(cnt==ind2) ind2el=nums2[j];
                cnt++;
                j++;
            }
        }

        while(i<nums1.size()){
            if(cnt==ind1) ind1el=nums1[i];
            if(cnt==ind2) ind2el=nums1[i];
            cnt++;
            i++;
        }

        while(j<nums2.size()){
            if(cnt==ind1) ind1el=nums2[j];
            if(cnt==ind2) ind2el=nums2[j];
            cnt++;
            j++;
        }

        if(n%2){
            return (double)ind2el;
        }

        return ((double)ind1el+(double)ind2el)/2.0;
    }
};