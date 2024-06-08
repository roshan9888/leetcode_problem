class Solution {
public:
    static bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        if (n<2) return 0; //its length is at least two
        unordered_map<int, int> mod_k;// 1 <= k <= 2^31 - 1
        int prefix=0;
        mod_k.reserve(n);
        mod_k[0]=-1;//sum can begin from index i=0
        for(int i=0; i<n; i++){
            prefix+=nums[i];
            prefix%=k;
            if (mod_k.count(prefix)){
                if(i>mod_k[prefix]+1) 
                    return 1;
            }
            else
                mod_k[prefix]=i;// mod_k[prefix]=i
        }
        return 0;
    }
      
};




auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();