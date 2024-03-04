bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
}

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        vector<pair<int, int>> vec(mp.begin(), mp.end());
        sort(vec.begin(), vec.end(), compare);
        string ans;
        for(auto it:vec){
            while(it.second--){
                ans+=it.first;
            }
        }
        return ans;
    }
};