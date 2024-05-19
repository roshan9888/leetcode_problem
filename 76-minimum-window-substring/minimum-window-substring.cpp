class Solution {
public:
    string minWindow(string s, string t) {
        //brute force
        // string ans="";
        // int len=INT_MAX;
        // for(int i=0;i<s.size();i++){
        //      unordered_map<char,int>mp;
        //     for(int i=0;i<t.size();i++){
        //     mp[t[i]]++;
        // }
        //     int count=t.size();
        //     for(int j=i;j<s.size();j++){
        //         if(mp.find(s[j])!=mp.end()){
        //             if(mp[s[j]]>0){
        //                 count--;
        //             }
        //             mp[s[j]]--;  
        //         }
        //         if(count==0){
        //             int winlen=j-i+1;
        //             if(winlen<len){
        //                 len=winlen;
        //                 ans=s.substr(i,len);
        //             }
        //             break;
        //         }
        //     }
        // }
        // return ans;

        //optimal solution
        int l=0;
        int r=0;
        int len=INT_MAX;
        int hash[256]={0};
        int index=-1;
        int n=s.size();
        int count=0;
        for(int i=0;i<t.size();i++){
            hash[t[i]]++;
        }
        while(r<n){
            if(hash[s[r]]>0){
                count++;
            }
            hash[s[r]]--;
            while(count==t.size()){
                if(r-l+1<len){
                    len=r-l+1;
                    index=l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0){
                    count--;
                }
            l++;
            }
            r++;
        }
        return index==-1?"":s.substr(index,len);
    }
};
