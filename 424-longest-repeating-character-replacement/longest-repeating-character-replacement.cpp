class Solution {
public:
    int characterReplacement(std::string s, int k) {
        int maxLength = 0;

        for (char letter = 'A'; letter <= 'Z'; ++letter) {
            int i = 0, j = 0, count = 0;

            while (j < s.size()) {
                if (s[j] != letter) {
                    count++;
                }

                while (count > k) {
                    if (s[i] != letter) {
                        count--;
                    }
                    i++;
                }

                maxLength = std::max(maxLength, j - i + 1);
                j++;
            }
        }
        return maxLength;
    }
};