class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        // ..brute force 
        // vector<vector<int>>nm(n,vector<int>(m));
        // for(int i=0;i<n;i++){
        //     int k=m;
        //     // cout<<k<<" ";
        //     for(int j=0;j<m;j++){
        //         k--;
        //         nm[i][j]=matrix[k][i];
        //         cout<<nm[i][j]<<" ";
        //         // cout<<k<<" ";
        //     }
        // }
        //n-1-i formula

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         matrix[i][j]=nm[i][j];
        //     }
        // } 

        //optimal solution
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};