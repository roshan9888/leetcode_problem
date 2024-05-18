class Solution {
public:
    // bool check(const string& sub) {
    //     unordered_map<char, int> mp;
    //     mp['a'] = 0;
    //     mp['b'] = 0;
    //     mp['c'] = 0;

    //     for (char ch : sub) {
    //         if (mp.find(ch) != mp.end()) {
    //             mp[ch]++;
    //         } else {
    //             return false;
    //         }
    //     }
    //     // cout<<sub<<" ";
    //     return mp['a'] >= 1 && mp['b'] >= 1 && mp['c'] >= 1;
    // }

    int numberOfSubstrings(string s) {
        //brute force approach
        // int count = 0;
        // for (int i = 0; i < s.size(); i++) {
        //     string sub;
        //     for (int j = i; j < s.size(); j++) {
        //         sub += s[j];
        //         if (check(sub)) {
        //             count++;
        //         }
        //     }
        // }
        // return count;

        //optimal solution
        int l=s.size();
        int ans=0;
        int start=0;
        int end=0;
        vector<int>occ(3);
        while(start<=end && end<l){
            char ch=s[end];
            occ[ch-97]++;
            while(occ[0] && occ[1] && occ[2]){
                ans+=l-end;
                occ[s[start]-97]--;
                start++;
            }
            end++;
        }
        return ans;
    }
};
