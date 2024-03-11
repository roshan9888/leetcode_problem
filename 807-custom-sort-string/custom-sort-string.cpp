class Solution {
public:
    string customSortString(string order, string s) {
        string temp;
        for(int i=0;i<order.size();i++){
            for(int j=0;j<s.size();j++){
                if(order[i]==s[j]){
                  temp+=order[i];
                }
            }
        }
        cout<<temp<<" ";
        unordered_map<char,int>mp;
        for(int i=0;i<temp.size();i++){
            mp[temp[i]]++;
        }
        for(auto it:mp){
            cout<<it.first<<" ";
        }
        for(int i=0;i<s.size();i++){
            if(!mp[s[i]]){
                temp+=s[i];
            }
        }
        return temp;
    }
};