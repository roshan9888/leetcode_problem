class Solution {
public:
    int pivotInteger(int n) {
        vector<int>arr;
        for(int i=1;i<=n;i++){
           arr.push_back(i);
        }
        int rightsum=(n*(n+1))/2;
        int leftsum=0;
        for(int i=0;i<arr.size();i++){
            rightsum-=arr[i];
            if(leftsum==rightsum){
                return i+1;
            }
            leftsum+=arr[i];
        }
        return -1;
    }
};