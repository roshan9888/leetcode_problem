class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> mp;
        for(int i = 0; i < chars.size(); i++) {
            mp[chars[i]]++;
        }
        int count = 0;
        for(int j = 0; j < words.size(); j++) {
            unordered_map<char,int> temp = mp; 
            bool canFormWord = true; 
            for(int i = 0; i < words[j].size(); i++) {
                char ch = words[j][i];
                if(temp.find(ch) != temp.end() && temp[ch] > 0) {
                    temp[ch]--; 
                } else {
                    canFormWord = false;
                    break;
                }
            }
            if(canFormWord) {
                count += words[j].size(); 
            }
        }
        return count;
    }
};