class Solution {
public:
    void solve(string digits,int ind,vector<string>&mapping,vector<string>&ans,string temp){
        if(ind>=digits.length()){
            ans.push_back(temp);
            return;
        }

        string s=mapping[digits[ind]-'0'];
        for(int i=0;i<s.size();i++){
            temp.push_back(s[i]);
            solve(digits,ind+1,mapping,ans,temp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.size()==0) return ans;
        vector<string>mapping(10);
        mapping[2]="abc";
        mapping[3]="def";
        mapping[4]="ghi";
        mapping[5]="jkl";
        mapping[6]="mno";
        mapping[7]="pqrs";
        mapping[8]="tuv";
        mapping[9]="wxyz";
        solve(digits,0,mapping,ans,"");
        return ans;
    }
};