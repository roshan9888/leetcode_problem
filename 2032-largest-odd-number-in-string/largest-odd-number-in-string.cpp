class Solution {
public:
    string largestOddNumber(string num) {
        string ans = "";
        int ind = -1;

        // Find the index from the last for the odd
        for(int i= num.length()-1; i>=0; i--){
            if((num[i] - '0') % 2 != 0){
                ind = i;
                break;
            }
        }

        // if index found then add all digits till that index.
        if(ind != -1){
            for(int i=0; i<=ind; i++){
                ans += num[i];
            }
        }

        return ans;
    }
};