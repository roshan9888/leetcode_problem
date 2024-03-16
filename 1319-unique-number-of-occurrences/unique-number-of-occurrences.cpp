class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        vector<int>check;
        for(auto it:mp){
            cout<<it.second<<" ";
            check.push_back(it.second);
        }
        sort(check.begin(),check.end());
        for(int i=0;i<check.size()-1;i++){
            if(check[i]==check[i+1]){
                return false;
            }
        }
        return true;
    }
};