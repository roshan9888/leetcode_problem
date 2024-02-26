class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int xor1=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==val){
               nums[i]=INT_MAX;
            }
        }
        int count=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=INT_MAX){
                count++;
            }
        }
        return count;
    }
};