class Solution {
public:
    // bool isPalindrome(string &s,int start,int end){
    //     if(start>=end){
    //         return true;
    //     }

    //     if(s[start]!=s[end]){
    //         return false;
    //     }
        
    //     return isPalindrome(s,start+1,end-1);;
    // } 

    bool isPalindrome(string &s,int start,int end,vector<vector<bool>> &dp){
        return dp[start][end];
    }
     
    void buildDPTable(const string &s, vector<vector<bool>> &dp) {
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }

        // Initialize two character substrings
        for (int i = 0; i < n - 1; ++i) {
            dp[i][i + 1] = (s[i] == s[i + 1]);
        }

        // Fill the dp table for substrings longer than 2
        for (int len = 3; len <= n; ++len) { // len is the length of the substring
            for (int i = 0; i < n - len + 1; ++i) {
                int j = i + len - 1; // Ending index of the substring

                // Check if s[i...j] is a palindrome
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                }
            }
        }
    }


    // void solve(string s,int ind,string&current,string&longest){
    //     if(ind>=s.size()){
    //         return;
    //     }

    //     for(int i=ind;i<s.size();i++){
    //         if(isPalindrome(s,ind,i)){
    //            string can=s.substr(ind,i-ind+1);
    //            if(can.size()>longest.size()){
    //              longest=can;
    //            }
    //            solve(s,i+1,current,longest);
    //         }
    //     }
    // }

    string longestPalindrome(string s) {
        // string longest;
        // string current;
        // solve(s,0,current,longest);  

        //optimize
        int n=s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        buildDPTable(s,dp);
        string longest="";
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(isPalindrome(s,i,j,dp)){
                    string curr=s.substr(i,j-i+1);
                    if(longest.size()<curr.size()){
                        longest=curr;
                    }
                }
            }
        }
        return longest;
    }
};