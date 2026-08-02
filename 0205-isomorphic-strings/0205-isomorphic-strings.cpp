class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char,char> st; // s → t
        unordered_map<char,char> ts; // t → s

        for (int i = 0; i < s.size(); i++) {
            char c1 = s[i];
            char c2 = t[i];

            // Check s → t mapping
            if (st.count(c1) && st[c1] != c2) {
                return false;
            }

            // Check t → s mapping
            if (ts.count(c2) && ts[c2] != c1) {
                return false;
            }

            // Store both mappings
            st[c1] = c2;
            ts[c2] = c1;
        }
        return true;
    }
};
