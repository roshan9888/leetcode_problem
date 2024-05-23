class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        map<int,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        int child=0;
        for(int i=0;i<g.size();i++){
            if(mp.find(g[i])!=mp.end()){
                mp[g[i]]--;
                if(mp[g[i]]==0) mp.erase(g[i]);
               child++;
            }else{
                auto it = mp.upper_bound(g[i]); // Find the first element greater than g[i]
            if (it != mp.end()) {
                it->second--;
                if(it->second==0){
                    mp.erase(it);
                }
                child++;
            }
            }
        }
        return child;
    }
};