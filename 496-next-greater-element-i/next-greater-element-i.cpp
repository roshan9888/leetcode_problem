class Solution {
public:
    int greater(int a,vector<int>&nums2){
        for(int i=0;i<nums2.size();i++){
            if(nums2[i]==a){
                for(int j=i;j<nums2.size();j++){
                   if(nums2[j]>a){
                    return nums2[j];
                   }
                }
            }
        }
        return -1;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i=0;i<nums2.size();i++){
            mp[nums2[i]]++;
        }

        for(int i=0;i<nums1.size();i++){
            if(mp[nums1[i]]){
               ans.push_back(greater(nums1[i],nums2));
            }
        }
        return ans;
    }
};