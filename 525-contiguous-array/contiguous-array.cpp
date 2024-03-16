class Solution {
public:
    int findMaxLength(vector<int>& arr) {
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0){
                arr[i]=-1;
            }
        }
        unordered_map<int,int>map;
        int csum=0;
        int ans=0;
        for(int i=0;i<arr.size();i++){
            csum+=arr[i];
            if(csum==0){
                ans=max(ans,i+1);
            }
            else if(map.find(csum)==map.end()){
                map[csum]=i;
            }
            else{
                ans=max(ans,i-map[csum]);
            }
        }
        return ans;
    }
};