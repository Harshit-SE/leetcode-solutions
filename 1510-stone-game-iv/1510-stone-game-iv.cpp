class Solution {
public:
    vector<int> dp;

    bool solve(int n) {
        if (n == 0) return false;
        if (dp[n] != -1) return dp[n] == 1 ? true : false;

        for (int i = 1; i * i <= n; i++) {   // use <= to include perfect squares
            if (solve(n - i * i) == false) {
                dp[n] = 1;   // mark as winning
                return true;
            }
        }
        dp[n] = 0;   // mark as losing
        return false;
    }

    bool winnerSquareGame(int n) {
        dp.assign(n + 1, -1);   // initialize dp with -1
        return solve(n);
    }
};
