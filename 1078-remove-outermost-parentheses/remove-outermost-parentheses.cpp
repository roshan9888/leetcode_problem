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
                temp+=s[i];
                st.pop();
            }
            else{
                temp+=s[i];
                st.push(s[i]);
            }
            if(st.empty()){
                v.push_back(temp);
                temp="";
            }
        }
        string sub="";
        for (const auto& str : v) {
        if (str.length() >= 2) {  // Ensure the string has at least two characters
            sub += str.substr(1, str.length() - 2);
            // cout << "Substring without first and last character of " << str << ": " << sub << endl;
        } 
    }
        return sub;
    }
};