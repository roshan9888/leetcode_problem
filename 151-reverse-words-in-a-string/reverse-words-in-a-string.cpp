class Solution {
public:
    string reverseWords(string s) {
        stack<char>st;
        stack<string>ans;
        for(int i=0;i<s.size();i++){
            string temp="";
            if(s[i]!=' '){
                st.push(s[i]);
            }
            else{
                while(!st.empty()){
                    temp.push_back(st.top());
                    st.pop();
                }

                if(temp.size()!=0){
                    reverse(temp.begin(),temp.end());
                    ans.push(temp);
                }
            }
        }
        string temp="";
        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }

        if(temp.size()!=0){
            reverse(temp.begin(),temp.end());
            ans.push(temp);
        }

        string finalans="";
        while(!ans.empty()){
            finalans+=ans.top();
            finalans+=" ";
            ans.pop();
        }

        finalans=finalans.substr(0,finalans.length()-1);
        return finalans;
    }
};