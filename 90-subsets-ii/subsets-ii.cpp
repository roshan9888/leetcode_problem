class Solution {
public:
    vector<vector<int>> v;

    void solve(int i, vector<int>& nums, vector<int>& subset) {
        // Add the current subset to the result
        v.push_back(subset);
        for (int j = i; j < nums.size(); j++) {
            if (j > i && nums[j] == nums[j - 1])
                continue;
            subset.push_back(nums[j]);
            solve(j + 1, nums, subset);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>subset;
        sort(nums.begin(),nums.end());
        solve(0, nums, subset);
        return v;
    }
};