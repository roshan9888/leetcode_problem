class Solution {
public:
    bool happynumber(int n,unordered_set<int> &visited){
        stack<int>st;
        if(n==1) return true;

        while(n){
            int a=n%10;
            st.push(a);
            n=n/10; 
        }
        int ans=0;
        while(!st.empty()){
            int sum=st.top();
            sum=sum*sum;
            ans+=sum;
            st.pop();
        }

        if (visited.find(ans) != visited.end()) {
            return false; 
        }
        visited.insert(ans);
        return happynumber(ans,visited);

    }
    bool isHappy(int n) {
        unordered_set<int> visited;
        return happynumber(n,visited);
    }
};