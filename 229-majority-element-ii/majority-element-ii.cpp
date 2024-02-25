class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //better solution
        // vector<int>ans;
        // int n=nums.size();
        // int m=floor(n/3);
        
        // unordered_map<int,int>mp;
        // for(int i=0;i<n;i++){
        //     mp[nums[i]]++;
        // }

        // for(auto it:mp){
        //     if(it.second>m){
        //         ans.push_back(it.first);
        //     }
        // }
        // return ans;
        
        // optimal solution
        int n=nums.size();
        int m=floor(n/3);
        cout<<m<<" ";
        vector<int>ans;
        int count1=0;
        int count2=0;
        int ele1=INT_MIN;
        int ele2=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(count1==0 && nums[i]!=ele2){
                count1++;
                ele1=nums[i];
            }
            else if(count2==0 && nums[i]!=ele1){
                count2++;
                ele2=nums[i];
            }
            else if(ele1==nums[i]){
                count1++;
            }
            else if(ele2==nums[i]){
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        int ct1=0,ct2=0;
        for(int i=0;i<n;i++){
            if(ele1==nums[i]) ct1++;
            if(ele2==nums[i]) ct2++;
        }

        if(ct1>m) ans.push_back(ele1);
        if(ct2>m) ans.push_back(ele2);
        return ans;
    }
};