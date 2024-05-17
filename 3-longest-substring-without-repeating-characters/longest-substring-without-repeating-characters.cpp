class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //brute force
    //     if(s.size()==0) return 0;
    //     if(s.size()==1) return 1;
    //     int maxstr=INT_MIN;
    //     for(int i=0;i<s.length();i++){
    //         unordered_set<int>st;
    //         for(int j=i;j<s.length();j++){
    //             if(st.find(s[j])!=st.end()){
    //                 // maxstr=max(maxstr,j-i+1);
    //                 break;
    //             }
    //         st.insert(s[j]);
    //         maxstr=max(maxstr,j-i+1);
    //         }
    //     }
    //     return maxstr;

    //optimal solution
    int i=0;
    int j=0;
    unordered_map<char,int>mp;
    int maxstr=0;
    while(j<s.size()){
       if(mp.find(s[j])!=mp.end()){
        i=max(i,mp[s[j]]+1);
       }
       mp[s[j]]=j;
       maxstr=max(maxstr,j-i+1);
       j++;
    }
    return maxstr;
    }
};