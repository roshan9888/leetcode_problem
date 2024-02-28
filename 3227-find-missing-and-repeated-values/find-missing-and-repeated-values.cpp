class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        // map<int,int>mp;
        // int n=grid.size();
        // for(int i=0;i<grid.size();i++){
        //     for(int j=0;j<grid.size();j++){
        //         mp[grid[i][j]]++;
        //     }
        // }
        // for(auto it:mp){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        // vector<int>ans;
        // for(auto it:mp){
        //    if(it.second>=2){
        //        ans.push_back(it.first);
        //    }
        // }
        // for(int i=1;i<=n*n;i++){
        //    if(mp.find(i)==mp.end()){
        //     ans.push_back(i);
        // }
        // }
        // return ans;

        //without using map
        int n = grid.size(),sum=0;
        vector<int> s;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                sum+=grid[i][j];
                s.push_back(grid[i][j]);
            }
        }
        sort(s.begin(),s.end());
        vector<int> ans(2);
        for(int i=0;i<s.size();i++)
        {
            if(i>0&&s[i]==s[i-1])
            {
                ans[0]=s[i-1];
            }
        }
        int m=n*n,count=(m*(m+1))/2;
        
        ans[1]=count-(sum-ans[0]);
       
        return ans;
    }
};