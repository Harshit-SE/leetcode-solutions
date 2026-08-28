class Solution {
public:
    string removeKdigits(string num, int k) {

        if (num.size() == k)
            return "0";

        string st;

        for (char c : num) {

            while (!st.empty() && k > 0 && st.back() > c) {
                st.pop_back();
                k--;
            }

            st.push_back(c);
        }

        // If k digits are still remaining,
        // remove them from the end
        while (k > 0) {
            st.pop_back();
            k--;
        }

        // Remove leading zeros
        int i = 0;

        while (i < st.size() && st[i] == '0') {
            i++;
        }

        st = st.substr(i);

        if (st.empty())
            return "0";

        return st;
    }
};