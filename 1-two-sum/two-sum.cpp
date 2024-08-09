bool cmp(pair<int,int>a,pair<int,int>b){
       return a.first<b.first;
}
class Solution {
public:
    
    vector<int> twoSum(vector<int>& nums, int target) {
      //brute force solution

    //   for(int i=0;i<nums.size()-1;i++){
    //       for(int j=i+1;j<nums.size();j++){
    //           if(nums[i]==target-nums[j]){
    //               return {i,j};
    //           }
    //       }
    //   }

    //   return {0,0};

    //better.  O(n^2) when use unordered_map in worst case || O(nlogn) when use ordered_map
    // map<int,int>mp;
    // for(int i=0;i<nums.size();i++){
    //     int a=nums[i];
    //     int b=target-a;
    //     if(mp.find(b)!=mp.end()){
    //         return {mp[b],i};
    //     }
    //     mp[a]=i;
    // }
    // return {-1,-1};

    //optimal solution
    vector<pair<int,int>>data;
    vector<int>ans;
    for(int i=0;i<nums.size();i++){
        int value=nums[i];
        int ind=i;
        data.push_back({value,ind});
    }
    sort(data.begin(),data.end(),cmp);
    int start=0;
    int end=nums.size()-1;
    while(start<end){
        if(data[start].first+data[end].first==target){
            ans.push_back(data[start].second);
            ans.push_back(data[end].second);
            break;
        }
        else if(data[start].first+data[end].first<target){
            start++;
        }
        else{
            end--;
        }
    }
    return ans;
    }
};