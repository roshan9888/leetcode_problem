class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return subsetXORSumRecursive(nums, 0, 0);
    }

    int subsetXORSumRecursive(vector<int>& nums, int index, int xorSumSoFar) {
        if (index == nums.size()) {
            return xorSumSoFar;
        }

        int includeCurrent = subsetXORSumRecursive(nums, index + 1, xorSumSoFar ^ nums[index]);

        int excludeCurrent = subsetXORSumRecursive(nums, index + 1, xorSumSoFar);

        return includeCurrent + excludeCurrent;
    }
};
