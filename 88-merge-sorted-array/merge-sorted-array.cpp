class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //brute force 
        // int i=m;
        // for (int j = 0;j<n; j++){
        //     nums1[i] = nums2[j];
        //     i++;
        // }
        // sort(nums1.begin(),nums1.end());gn

        // time complexity O(m+n)+O(nlogn)

        //optimal solution
        int i=m-1;
        int j=n-1;
        int k=m+n-1;

        while(j>=0){
            if(i>=0 && nums1[i]>nums2[j]){
                nums1[k--]=nums1[i--];
            }
            else{
                nums1[k--]=nums2[j--];
            }
        }

        // time complexity O(m+n)
    }
};