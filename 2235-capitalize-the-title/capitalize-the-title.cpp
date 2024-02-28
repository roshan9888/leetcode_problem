class Solution {
public:
    string capitalizeTitle(string s) {
        vector<string> words;
        istringstream iss(s);
        string word;
        while (iss >> word) {
            words.push_back(word);
        }

        for(auto &it:words){
            if(it.size()>2){
                it[0] = toupper(it[0]);
                for(size_t i = 1; i < it.size(); ++i) {
                it[i] = tolower(it[i]);
            }
            }
            if(it.size()<=2){
                for(size_t i = 0; i < it.size(); ++i) {
                it[i] = tolower(it[i]);
            }
        }
        }
        string ans="";
        for(size_t i=0;i<words.size();i++){
            if(i>0){
                ans+=" ";
            }
            ans+=words[i];
        }
        return ans;
    }
};