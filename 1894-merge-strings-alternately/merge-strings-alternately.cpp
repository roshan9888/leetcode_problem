class Solution {
public:
    std::string mergeAlternately(std::string word1, std::string word2) {
        int i = 0;
        int j = 0;
        stack<char> st;
        while (i < word1.size() && j < word2.size()) {
            std::string str;
            st.push(word1[i]);
            st.push(word2[j]);
            // st.push(str);
            i++;
            j++;
        }
        while (i < word1.size()) {
            std::string str;
            st.push(word1[i]);
            // st.push(str);
            i++;
        }

        while (j < word2.size()) {
            std::string str;
            st.push(word2[j]);
            // st.push(str);
            j++;
        }

        std::string ans;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};
