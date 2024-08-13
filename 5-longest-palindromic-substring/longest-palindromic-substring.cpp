class Solution {
public:
    bool isPalindrome(string &s,int start,int end){
        if(start>=end){
            return true;
        }

        if(s[start]!=s[end]){
            return false;
        }
        
        return isPalindrome(s,start+1,end-1);;
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
        string longest="";
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(isPalindrome(s,i,j)){
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