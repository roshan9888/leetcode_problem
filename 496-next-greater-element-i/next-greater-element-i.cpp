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

    // vector<int>nextgreaterelement(vector<int>&nums2){
    //     int n=nums2.size();
    //     vector<int>nge(n,-1);
    //     stack<int>st;
    //     for(int i=2*n-1;i>=0;i--){
    //         while(!st.empty() && st.top()<=nums2[i%n]){
    //             st.pop();
    //         }

    //         if(i<n){
    //             if(!st.empty()) nge[i]=st.top();
    //         }
    //         st.push(nums2[i%n]);
    //     }
    //     return nge;
    // }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // vector<int>ans;
        // unordered_map<int,int>mp;
        // for(int i=0;i<nums2.size();i++){
        //     mp[nums2[i]]++;
        // }        

        // for(int i=0;i<nums1.size();i++){
        //     if(mp[nums1[i]]){
        //         ans.push_back(greater(nums1[i],nums2));
        //     }
        // }
        // return ans;

        //using stack O(n) for a circular array
        // vector<int>ans=nextgreaterelement(nums2);
        // return ans;

        //optimal 
        unordered_map<int,int>nge;
        vector<int>ans;
        stack<int>st;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            nge[nums2[i]]=st.empty()?-1:st.top();
            st.push(nums2[i]);
        }

        for(auto it:nums1){
            ans.push_back(nge[it]);
        }
        return ans;
    }
};