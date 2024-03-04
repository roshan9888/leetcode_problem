class Solution {
public:
    int maxDepth(string s) {
        // stack<char>st;
        // int maxi=0;
        // int count=0;
        // cout<<s.size()<<" ";
        // if(s.size()==1 || s.size()==0) return 0;
        // for(int i=0;i<s.size();i++){
        //     if(s[i]=='('){
        //         st.push(s[i]);
        //     }
        //     if(s[i]==')' && st.top()=='('){
        //        st.pop();
        //        count++;
        //        maxi=max(maxi,count);
        //        if(st.empty()){
        //            count=0;
        //        }
        //     }
        // }
        // return count;

        stack<char> st;
        int maxi = 0;
        int count = 0;
        
        for (char ch : s) {
            if (ch == '(') {
                st.push(ch);
                count++;
                maxi = max(maxi, count);
            } else if (ch == ')' && !st.empty() && st.top() == '(') {
                st.pop();
                count--;
            }
        }
        
        return maxi;
    }
};