class Solution {
public:
    bool solve(int ind,string s,unordered_set<string>&mp){
        if(ind>=s.size()){
            return true;
        }

        if(mp.find(s)!=mp.end()){
            return true;
        }
        for(int l=1;l<=s.size();l++){
            string temp=s.substr(ind,l);
            if(mp.find(temp)!=mp.end() && solve(ind+l,s,mp)){
                return true;
            }
        }
        return false;
    }

    bool topdown(int ind,string s,unordered_set<string>&mp,vector<int>&dp){
        if(ind>=s.size()){
            return true;
        }
        
        if(dp[ind]!=-1){
            return dp[ind];
        }
        if(mp.find(s)!=mp.end()) return true;
        for(int l=1;l<=s.size();l++){
            string temp=s.substr(ind,l);
            if(mp.find(temp)!=mp.end() && topdown(ind+l,s,mp,dp)){
                return dp[ind]=true;
            }
        }
        return dp[ind]=false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>mp;
        for(auto it:wordDict){
            mp.insert(it);
        }
        // return solve(0,s,mp);
        // for(auto it:mp){
        //     cout<<it<<" ";
        // }

        //top down dp
        vector<int>dp(s.size(),-1);
        return topdown(0,s,mp,dp);
    }
};