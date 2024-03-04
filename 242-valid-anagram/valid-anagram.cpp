class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp;
        if(s.size()!=t.size()) return false;
        for(int i=0;i<s.size();i++){
              mp[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            mp[t[i]]--;
        }
        cout<<mp.size()<<" ";
        for(auto it:mp){
            if(it.second>0){
                return false;
            }
        }
        return true;
    }
};