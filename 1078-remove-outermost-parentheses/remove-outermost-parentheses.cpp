class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>st;
        vector<string>v;
        string temp="";
        for(int i=0;i<s.size();i++){
            if(st.empty()){
                st.push(s[i]);
                temp+=s[i];
            }
            else if(st.top()=='(' && s[i]==')'){
                st.pop();
                temp+=s[i];
            }
            else{
                st.push(s[i]);
                temp+=s[i];
            }
            if(st.empty()){
                v.push_back(temp);
                temp="";
            }
        }

        string ans="";
        for(auto it:v){
            if(it.length()>=2){
                ans+=it.substr(1,it.length()-2);
            }
        }
        return ans;
    }
};