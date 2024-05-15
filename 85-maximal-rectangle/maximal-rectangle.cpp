class Solution {
public:
    int find_max(vector<int>&arr){
        int n=arr.size();
        vector<int>left(n);
        vector<int>right(n);
        stack<int>s;
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            while(!s.empty() && arr[s.top()]>=arr[i]){
                s.pop();
            }
            if(s.empty()) left[i]=0;
            else left[i]=s.top()+1;
            s.push(i);
        }

        //clear the stack for reuse
        while(!s.empty()) s.pop();

        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()]>=arr[i]){
                s.pop();
            }
            if(s.empty()) right[i]=n-1;
            else right[i]=s.top()-1;
            s.push(i);

            ans=max(ans,(right[i]-left[i]+1)*arr[i]);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row=matrix.size();
        cout<<row<<" ";
        int col=matrix[0].size();
        cout<<col<<" ";
        vector<int>arr(col,0);
        int maxi=INT_MIN;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]-'0'==0){
                    arr[j]=0;
                }
                else{
                arr[j]+=matrix[i][j]-'0';
                }
            }
            maxi=max(maxi,find_max(arr));
        }
        
        // for(int it:arr){
        //     cout<<it<<" ";
        // }
        
        // return 1;
        return maxi;
    }
};