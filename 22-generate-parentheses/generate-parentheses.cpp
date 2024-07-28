class Solution {
public:
    void generate(int n,int open,int close,vector<string>&ans,string temp){
        // if(open==n){
        //     while(close<n){
        //         temp+=')';
        //         close++;
        //     }
        //     ans.push_back(temp);
        //     return;
        // }

        // if(open>close){
        //     generate(n,open+1,close,ans,temp+'(');
        //     generate(n,open,close+1,ans,temp+')');
        // }
        // else{
        //     generate(n,open,close+1,ans,temp+')');
        // }

        if (open == n && close == n) {
            ans.push_back(temp);
            return;
        }

        if (open < n) {
            generate(n, open + 1, close, ans, temp + '(');
        }

        if (close < open) {
            generate(n, open, close + 1, ans, temp + ')');
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        generate(n,0,0,ans,"");
        return ans;
    }
};