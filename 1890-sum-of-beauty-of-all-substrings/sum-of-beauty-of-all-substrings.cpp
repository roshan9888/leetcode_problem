// class Solution {
// public:
//     void beauty(string &s, int i, int j, int& mostfre, int& leastfre) {
//         map<char, int> freqMap;

//         while (i <= j) {
//             freqMap[s[i]]++;
//             i++; 
//         }

//         mostfre = INT_MIN;
//         leastfre = INT_MAX;

//         for (auto it : freqMap) {
//             if (it.second > mostfre) {
//                 mostfre = it.second;
//             }
//             if (it.second < leastfre) {
//                 leastfre = it.second;
//             }
//         }
//     }

//     int beautySum(string s) {
//         //brute force
//         int count=0;
//         for(int i=0;i<s.size();i++){
//             for(int j=i;j<s.size();j++){
//                 int mostfre, leastfre;
//                 beauty(s, i, j, mostfre, leastfre);
//                 count += (mostfre - leastfre);
//             }
//         }
//         return count;

//         //optimal solution

//     }
// };

class Solution {
public:
    int minimum(vector<int> &mp){
        int k = INT_MAX;
        for(auto it : mp){
            if(it<=k && it>0)
                k = it;
        }
        return k;
    }
    int maximum(vector<int> &mp){
        int k = INT_MIN;
        for(auto it : mp){
            if(it>=k)
                k = it;
        }
        return k;
    }
    int beautySum(string s) {
        int sum = 0;
        for(int i = 0; i<s.size();i++){
            vector<int> mp(26,0);
            for(int j=i; j<s.size();j++){
                mp[s[j]-'a']++;
                int mx = maximum(mp);
                int mn = minimum(mp);
                sum += mx - mn;
            }
        }
        return sum;
    }
};