class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        map<int,int>mp;
        int n=grid.size();
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                mp[grid[i][j]]++;
            }
        }
        for(auto it:mp){
            cout<<it.first<<" "<<it.second<<endl;
        }
        vector<int>ans;
        for(auto it:mp){
           if(it.second>=2){
               ans.push_back(it.first);
           }
        }
        for(int i=1;i<=n*n;i++){
           if(mp.find(i)==mp.end()){
            ans.push_back(i);
        }
        }
        
        return ans;
    }
};