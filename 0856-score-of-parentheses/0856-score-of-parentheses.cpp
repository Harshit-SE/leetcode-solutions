class Solution {
public:
    int scoreOfParentheses(string s) {
        vector<int> v;
        v.push_back(0);

        for (char c : s) {
            if (c == '(') {
                v.push_back(0);
            } 
            else {
                int count = v.back();
                v.pop_back();

                int score = (count == 0) ? 1 : 2 * count;

                v.back() += score;
            }
        }

        return v.back();
    }
};