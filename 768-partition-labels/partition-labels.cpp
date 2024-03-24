class Solution {
public:
    vector<int> partitionLabels(string s) {
       map<char,int>last;
       vector<int>res;
       for(int i=0;i<s.size();i++){
        last[s[i]]=i;
       }

       int endp=last[s[0]];
       int startp=0;

       while(startp<s.length()){
        endp=last[s[startp]];
        int cnt=0;
        while(startp<=endp){
            cnt++;
            endp=max(endp,last[s[startp]]);
            startp++;
        }
        res.push_back(cnt);
       }
       return res;
    }
};