bool cmp(string&s1,string&s2){
    return s1.size()<s2.size();
} 
class Solution {
public:
    bool compare(string&s1,string&s2){
        if(s1.size()!=s2.size()+1) return false;
        int f=0;
        int s=0;
        while(f<s1.size()){
            if(s<s2.size() && s1[f]==s2[s]){
                f++;
                s++;
            }
            else{
                f++;
            }
        }
        return (f==s1.size() && s==s2.size()) ? true : false;
    }
     
    
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        vector<int>dp(n+1,1);
        int maxi=1;
        sort(words.begin(),words.end(),cmp);
        for(int i=0;i<n;i++){
            for(int pre=0;pre<i;pre++){
                if(compare(words[i],words[pre]) && 1+dp[pre]>dp[i]){
                    dp[i]=1+dp[pre];
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
            }
        }
        return maxi;
    }
};