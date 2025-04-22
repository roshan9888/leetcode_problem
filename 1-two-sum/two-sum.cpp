bool cmp(pair<int,int>a,pair<int,int>b){
    return a.first<b.first;
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         if(nums[i]+nums[j]==target){
        //             return {i,j};
        //         }
        //     }
        // }
        // return {};

        int i=0;
        int j=nums.size()-1;
        vector<pair<int,int>>data;
        for(int i=0;i<nums.size();i++){
            int value=nums[i];
            int ind=i;
            data.push_back({value,ind});
        }
        sort(data.begin(),data.end(),cmp);
        while(i<j){
            if(data[i].first+data[j].first==target){
                return {data[i].second,data[j].second};
            }
            else if(data[i].first+data[j].first>target){
                j--;
            }
            else{
                i++;
            }
        }
        return {};
    }
};