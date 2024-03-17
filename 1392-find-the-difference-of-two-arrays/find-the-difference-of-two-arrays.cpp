class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int>s1;
        set<int>s2;
        for(int i=0;i<nums1.size();i++){
            s1.insert(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++){
            s2.insert(nums2[i]);
        }
        vector<int>n1;
        vector<int>n2;
        for(auto it:s1){
            n1.push_back(it);
        }
        for(auto it:s2){
            n2.push_back(it);
        }
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;
        vector<vector<int>> ans(2); // Initialize the answer vector with 2 empty vectors

        // Fill the frequency maps
        for (int num : n1) {
            mp1[num]++;
        }
        for (int num : n2) {
            mp2[num]++;
        }

        // Fill the first vector in the answer
        for (int num : n1) {
            if (mp2.find(num) == mp2.end()) {
                ans[0].push_back(num);
            }
        }

        // Fill the second vector in the answer
        for (int num : n2) {
            if (mp1.find(num) == mp1.end()) {
                ans[1].push_back(num);
            }
        }

        return ans;
    }
};