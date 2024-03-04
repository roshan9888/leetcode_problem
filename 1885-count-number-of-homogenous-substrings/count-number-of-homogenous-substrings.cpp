class Solution {
public:
    int countHomogenous(string s) {
        long long count=1;
        char curr=s[0];
        long long ans=0;
        for(int i=1;i<s.size();i++){
            if(s[i]==curr){
                count++;
            }
            else{
                ans+=(count*(count+1))/2;
                count=1;
                curr=s[i];
            }
        }
        ans+=count*(count+1)/2;
        return ans%1000000007;
    }
};