class Solution {
public:
    void solve(int ind, string temp, long long sum, long long prev, string &num, int target, vector<string>& ans) {
        if (ind == num.size()) {
            if (sum == target) {
                ans.push_back(temp);
            }
            return; // Ensure the function returns after checking the base case
        }

        for (int i = ind; i < num.size(); i++) {
            // Avoid numbers with leading zeros
            if (i > ind && num[ind] == '0') {
                break; // Use break to skip further processing in this loop
            }
            long long number = stoll(num.substr(ind, i - ind + 1));
            if (ind == 0) {
                // Initial case with no operator
                solve(i + 1, temp + num.substr(ind, i - ind + 1), number, number, num, target, ans);
            } else {
                // Addition
                solve(i + 1, temp + "+" + num.substr(ind, i - ind + 1), sum + number, number, num, target, ans);
                // Subtraction
                solve(i + 1, temp + "-" + num.substr(ind, i - ind + 1), sum - number, -number, num, target, ans);
                // Multiplication
                solve(i + 1, temp + "*" + num.substr(ind, i - ind + 1), sum - prev + (prev * number), prev * number, num, target, ans);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        solve(0, "", 0, 0, num, target, ans);
        return ans;
    }
};
