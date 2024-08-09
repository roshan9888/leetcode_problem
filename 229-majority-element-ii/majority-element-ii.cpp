class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1=0;
        int count2=0;
        int ele1=INT_MIN;
        int ele2=INT_MIN;
        int m=floor(nums.size()/3);
        for(int i=0;i<nums.size();i++){
            if(count1==0 && nums[i]!=ele2){
                count1++;
                ele1=nums[i];
            }
            else if(count2==0 && nums[i]!=ele1){
                count2++;
                ele2=nums[i];
            }
            else if(nums[i]==ele1){
                count1++;
            }
            else if(nums[i]==ele2){
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }

        int cnt1=0;
        int cnt2=0;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ele1) cnt1++;
            if(nums[i]==ele2) cnt2++;
        }
        if(cnt1>m) ans.push_back(ele1);
        if(cnt2>m) ans.push_back(ele2);
        return ans;
    }
};