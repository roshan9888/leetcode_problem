class Solution {
public:
    bool checkPal(string &str, int start, int end){
        while(start <= end){
            if(str[start] != str[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void generatePalindrome(int idx, vector<string> &temp, vector<vector<string>> &result, string &s){
        if(idx == s.size()){
            result.push_back(temp);
            return;
        }
        
        for(int i = idx; i < s.size(); i++){
            if(checkPal(s, idx, i)){
                temp.push_back(s.substr(idx, i - idx + 1));
                generatePalindrome(i + 1, temp, result, s);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> temp;
        generatePalindrome(0, temp, result, s);
        return result;
    }
};