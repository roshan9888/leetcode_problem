class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0;
        int j=0;
        int count=0;
        if(s.size()==0) return true;
        while(j<t.size()){
            if(s[i]==t[j]){
                i++;
                j++;
                count++;
            }
            else{
                j++;
            }
        }
        return count==s.size() ? true : false;
    }
};