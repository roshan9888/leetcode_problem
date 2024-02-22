class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int m=floor(n/2);
        cout<<m<<" ";
        for(int i=0;i<n;i++){
            int count=0;
            int occur=nums[i];
            for(int j=0;j<n;j++){
                if(nums[j]==occur){
                    count++;
                }
            }
            if(count>m){
                cout<<count<<" ";
                return occur;
            }
        }
        return -1;
    }
};