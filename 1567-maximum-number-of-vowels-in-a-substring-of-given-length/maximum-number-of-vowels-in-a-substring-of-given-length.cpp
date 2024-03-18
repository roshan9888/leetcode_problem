class Solution {
public:
    bool isVowel(char s){
        if(s=='a' || s=='e' || s=='i' || s=='o' || s=='u')
            return true;
        return false;    
    }
    int maxVowels(string s, int k) {
        int vowelcount=0;
        int maxvowel=0;
        for(int i=0;i<k;i++){
            if(isVowel(s[i])){
                vowelcount++;
            } 
        }
        maxvowel=vowelcount;

        for(int i=k;i<s.length();i++){
            if(isVowel(s[i])){
                vowelcount++;
            }

            if(isVowel(s[i-k])){
                vowelcount--;
            }

            maxvowel=max(vowelcount,maxvowel);
        }
        return maxvowel;
    }
};