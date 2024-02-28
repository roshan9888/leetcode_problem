class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        if(nums.size()==0) return ans;
        int start=nums[0];
        int prev=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]>prev+1){
                if(start!=prev){
                 string entry = to_string(start) + "->" + to_string(prev);
                 ans.push_back(entry);
                }
                else{
                  string entry = to_string(prev);
                   ans.push_back(entry);
                }
                start=nums[i];
                prev=nums[i];
            }
            else{
                prev=nums[i];
            }
        }

                if(start!=prev){
                   string entry = to_string(start) + "->" + to_string(prev);
                   ans.push_back(entry);
                }
                else{
                   string entry = to_string(prev);
                   ans.push_back(entry);
                }
        return ans;
    }
};