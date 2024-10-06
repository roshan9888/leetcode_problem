class Solution {
public:
    bool solve(vector<vector<char>>&board,int ind,string word,int i,int j){
        if(ind==word.size()) return true;

        if(i<0 || j<0 || i==board.size() || j==board[0].size() || board[i][j]!=word[ind]){
            return false;
        }
        bool a,b,c,d;
        board[i][j]='$';
        a=solve(board,ind+1,word,i+1,j);
        b=solve(board,ind+1,word,i-1,j);
        c=solve(board,ind+1,word,i,j+1);
        d=solve(board,ind+1,word,i,j-1);
        board[i][j]=word[ind];
        if(a || b || c || d) return true;

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<board[i].size();j++){
                bool x=false;
                if(board[i][j]==word[0]){
                    x=solve(board,0,word,i,j);
                }
                if(x) return true;
            }
        }
        return false;
    }
};