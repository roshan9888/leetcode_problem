class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        // vector<string>ans;
        // stack<int>s;
        // for(int i=n;i>=1;i--){
        //     s.push(i);
        // }
        // map<int,int>mp;
        // for(int i=0;i<target.size();i++){
        //     mp[target[i]]++;
        // }
        // while(!s.empty()){
        //     int top=s.top();
        //     s.pop();
        //     ans.push_back("Push");
        //     if(mp[top]){
        //         mp.erase(top);
        //     }else{
        //         ans.push_back("Pop");
        //     }
        //     if(mp.size()==0){
        //         return ans;
        //     }
        // }
        // return ans;

        vector<string> result;
        int i =0;
        int numberStream=1;
        while(i<target.size()){
            if(target[i]==numberStream){
                result.push_back("Push");
                i++;
                numberStream++;
            }else{
                result.push_back("Push");
                result.push_back("Pop");
                numberStream++;
            }
        }
        return result;
    }
};