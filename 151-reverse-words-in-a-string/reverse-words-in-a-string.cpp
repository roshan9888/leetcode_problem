class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        stack<char> st;
        stack<string> ans;

        for(int i=0; i<n; i++){
            string temp = "";
            if(s[i] != ' '){
                st.push(s[i]);
            }
            else{
                while(!st.empty()){
                    temp.push_back(st.top());
                    st.pop();
                }

                if(temp.size() != 0){
                    reverse(temp.begin(), temp.end());
                    ans.push(temp);
                }
            }
        }

        string temp = "";
        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }
        if(temp.size() != 0){
            reverse(temp.begin(), temp.end());
            ans.push(temp);
        }

        string finalAns = "";
        while(!ans.empty()){
            cout<<ans.top()<<" ";
            finalAns += ans.top();
            finalAns += " ";
            ans.pop();
        }

        finalAns = finalAns.substr(0, finalAns.size()-1);

        return finalAns;
    }
};