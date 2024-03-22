class Solution {
public:
    // void generateBinary(int num,string prefix,unordered_map<string,int>&mp){
    //     if(num==0){
    //         mp[prefix]=1;
    //     }else{
    //         generateBinary(num-1,prefix+"0",mp);
    //         generateBinary(num-1,prefix+"1",mp);
    //     }
    // }
    string findDifferentBinaryString(vector<string>& nums) {
        //brute force solution
        // int n=nums.size();
        // unordered_map<string,int>mp;
        // generateBinary(n,"",mp);
        // for(auto it:nums){
        //     if(mp[it]){
        //         mp[it]=-1;
        //     }
        // }
        // for(auto it:mp){
        //     if(it.second!=-1){
        //         return it.first;
        //     }
        // }
        // return "";
    
        //optimal solution
        set<long long int>arr;
        for(auto it:nums){
            arr.insert(stoll(it,0,2));
        }
        int n=pow(2,nums.size());
        // arr.resize(n,-1);
        for(auto it:arr){
            cout<<it<<" ";
        }
        for(int i=0;i<n;i++){
            if(arr.find(i)==arr.end()){
                string ans = bitset<32>(i).to_string().substr(32 - nums.size());
                return ans;
            }
        }
        return "";
    }
};