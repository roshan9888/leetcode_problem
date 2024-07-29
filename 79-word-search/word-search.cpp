class Solution {
public:
    bool search(string word,int ind,vector<vector<char>>&board,int i,int j){
        if(ind==word.size()){
            return true;
        }

        if(i<0 || j<0 || i==board.size() || j==board[0].size() || board[i][j]!=word[ind]){
            return false;
        }
        bool a,b,c,d;
        board[i][j]='$';
        a=search(word,ind+1,board,i+1,j);
        b=search(word,ind+1,board,i-1,j);
        c=search(word,ind+1,board,i,j+1);
        d=search(word,ind+1,board,i,j-1);
        board[i][j]=word[ind];

        if(a || b || c || d) return true;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                bool x=false;
                if(board[i][j]==word[0]){
                    x=search(word,0,board,i,j);
                }
                if(x) return true;
            }
        }
        return false;
    }
};