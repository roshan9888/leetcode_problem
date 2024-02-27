class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int count=0;
        int n=s.size();
        bool flag=1;
        cout<<n<<" ";
        for(int i=n-1;i>=0;i--){
            if(s[i]==' ' && flag==1){
                continue;
            }
            else if(s[i]==' ' && flag==0){
                break;
            }
            else{
                count++;
                flag=0;
            }
        }
        return count;
    }
};