class Solution {
public:
    bool wordPattern(string pattern, string s) {
    istringstream iss(s);
        vector<string> words;
        string word;
        while (iss >> word) {
            words.push_back(word);
        }
        
        if (pattern.size() != words.size()) {
            return false;
        }
        
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;
        
        for (int i = 0; i < pattern.size(); ++i) {
            char ch = pattern[i];
            string w = words[i];
            
            if (charToWord.find(ch) == charToWord.end()) {
                if (wordToChar.find(w) != wordToChar.end()) {
                    return false;
                }
                charToWord[ch] = w;
                wordToChar[w] = ch;
            } else {
                if (charToWord[ch] != w) {
                    return false;
                }
            }
        }
        
        return true;
    }
};