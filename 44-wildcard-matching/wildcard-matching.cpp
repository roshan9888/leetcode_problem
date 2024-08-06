class Solution {
public: 
    bool solve(int i,int j,string &s,string &p){
        if(i<0 && j<0) return true;
        if(j<0 && i>=0) return false;
        if(i<0 && j>=0){
            for(int t=0;t<=j;t++){
                if(p[t]!='*') return false;
            }
            return true;
        }

        if(s[i]==p[j] || p[j]=='?'){
            return solve(i-1,j-1,s,p);
        }
        if(p[j]=='*') return solve(i-1,j,s,p) | solve(i,j-1,s,p);

        return false;
    }

    bool topdown(int i,int j,string &s,string &p,vector<vector<int>>&dp){
        if(i<0 && j<0) return true;
        if(j<0 && i>=0) return false;
        if(i<0 && j>=0){
            for(int t=0;t<=j;t++){
                if(p[t]!='*') return false;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j] || p[j]=='?'){
            return dp[i][j]=topdown(i-1,j-1,s,p,dp);
        }
        if(p[j]=='*') return dp[i][j]=topdown(i-1,j,s,p,dp) | topdown(i,j-1,s,p,dp);

        return false;
    }

    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        // return solve(n-1,m-1,s,p);

        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return topdown(n-1,m-1,s,p,dp);
    }
};