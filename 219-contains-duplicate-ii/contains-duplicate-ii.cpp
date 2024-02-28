class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        //brute force 
        // for(int i=0;i<nums.size()-1;i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         if(nums[i]==nums[j] && abs(i-j)<=k && i!=j){
        //             return true;
        //         }
        //     }
        // }
        // return false;

        // time complexity O(n^2)

        //optimal solution
        unordered_map<int,vector<int>>indexMap;
        for(int i=0;i<nums.size();i++){
            indexMap[nums[i]].push_back(i);
        }

        for(auto it:indexMap){
            if(it.second.size() ==2  && abs(it.second[0]-it.second[1])<=k){
              return true;
            }
            else if(it.second.size()>2){
                for(int i=0;i<it.second.size()-1;i++){
                    for(int j=i+1;j<it.second.size();j++){
                        cout<<abs(it.second[i]-it.second[j])<<" ";
                        if(abs(it.second[i]-it.second[j])<=k){
                            return true;
                        }
                    }
                }
                return false;
            }
        }
        return false;
    }
};