class Solution {
public:
    bool canConstruct(string s, string t) {
        
        if(s.length()>t.length()) return false;
        int alphabets_counter[26] = {0};
        for(char c : t){
            alphabets_counter[c-'a']++;
        }

        for(char c : s){
            if(alphabets_counter[c-'a']==0) return false;
            alphabets_counter[c-'a']--;
        }
        return true;
    }
};