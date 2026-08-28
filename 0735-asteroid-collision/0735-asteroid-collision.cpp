class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> st;

        for (int x : asteroids) {

            bool destroyed = false;

            // Collision happens only when:
            // top is moving right and x is moving left
            while (!st.empty() && st.top() > 0 && x < 0) {

                if (st.top() < -x) {
                    // Stack asteroid is smaller
                    st.pop();
                }
                else if (st.top() == -x) {
                    // Both explode
                    st.pop();
                    destroyed = true;
                    break;
                }
                else {
                    // Current asteroid is smaller
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed) {
                st.push(x);
            }
        }

        vector<int> ans(st.size());

        for (int i = ans.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};