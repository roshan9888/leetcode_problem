class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // int n=matrix.size();
        // int m=matrix[0].size();
        // vector<vector<int>>nmatrix=matrix;
        // //brute force solution
        // // time complexity O(n^3)
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(matrix[i][j]==0){
        //             for(int k=0;k<m;k++){
        //                 nmatrix[i][k]=0;
        //             }

        //             for(int l=0;l<n;l++){
        //                 nmatrix[l][j]=0;
        //             }
        //         }
        //     }
        // }
        // matrix=nmatrix;

        //better solution
       
        // vector<int>row(n,0);
        // vector<int>col(m,0);

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(matrix[i][j]==0){
        //             row[i]=1;
        //             col[j]=1;
        //         }
        //     }
        // }

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(row[i] || col[j]){
        //             matrix[i][j]=0;
        //         }
        //     }
        // }

        // time complexity O(n^2)

        //optimal solution
       int col0=1;
       int n=matrix.size();
       int m=matrix[0].size();
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                matrix[i][0]=0;
                if(j!=0){
                    matrix[0][j]=0;
                }
                else{
                    col0=0;
                }
            }
        }
       }

       for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(matrix[i][j]!=0){
                if(matrix[0][j]==0 || matrix[i][0]==0){
                    matrix[i][j]=0;
                }
            }
        }
       }

       if(matrix[0][0]==0){
        for(int i=0;i<m;i++){
            matrix[0][i]=0;
        }
       }

       if(col0==0){
        for(int i=0;i<n;i++){
             matrix[i][0]=0;
        }
       }

        // time complexity O(2nm)
        // space complexity O(1)
    }
};