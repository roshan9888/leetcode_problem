class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (int i = 0; i < asteroids.size(); ++i) {
            if (st.empty() || asteroids[i] > 0 || st.top() < 0) {
                st.push(asteroids[i]);
            } else {
                while (!st.empty() && st.top() > 0 && st.top() < abs(asteroids[i])) {
                    st.pop();
                }
                if (st.empty() || st.top() < 0) {
                    st.push(asteroids[i]);
                } else if (st.top() == abs(asteroids[i])) {
                    st.pop(); // Destroy both asteroids
                }
            }
        }
        
        std::vector<int> ans;
        while (!st.empty()) {
            ans.insert(ans.begin(), st.top());
            st.pop();
        }
        
        return ans;
    }
};