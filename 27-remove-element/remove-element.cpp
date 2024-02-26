class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // int xor1=0;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==val){
        //        nums[i]=INT_MAX;
        //     }
        // }
        // int count=0;
        // sort(nums.begin(),nums.end());
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]!=INT_MAX){
        //         count++;
        //     }
        // }
        // return count;

        int i=0;
        int j=nums.size()-1;
        while(i<j){
            if(nums[i]==val && nums[j]==val){
                j--;
            }
            else if(nums[i]==val && nums[j]!=val){
                cout<<nums[i]<<"swap"<<nums[j]<<" ";
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
            else if(nums[i]!=val && nums[j]==val){
            //    cout<<nums[i]<<"swap"<<nums[j]<<" ";
               i++;
               j--;
            }
            else{
            i++;
            }
        }
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                count++;
            }
        }
        cout<<count<<" ";
        return count;
    }
};