class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //brute force solution
        // int count=0;
        // for(int i=0;i<nums.size();i++){   
        //     int sum=0;  
        //     for(int j=i;j<nums.size();j++){
        //         sum+=nums[j];
        //         if(sum==k){
        //             count++;
        //         }
        //     }
        // }
        // return count;
       
        //optimal solution
        unordered_map<int,int>mp;
        int n=nums.size();
        mp[0]=1;
        int presum=0;
        int count=0;
        for(int i=0;i<n;i++){
            presum+=nums[i];
            int rem=presum-k;
            count+=mp[rem];
            mp[presum]+=1;
        }
        return count;
    }
};

