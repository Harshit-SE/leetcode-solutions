class Solution {
public:
    vector<vector<int>> dp;
  // SAME AS LCS
  
    int solve(vector<int>& coins, int amount, int i) {

        if (amount == 0)
            return 0;

        if (amount < 0 || i == coins.size())
            return INT_MAX;

        if (dp[i][amount] != -1)
            return dp[i][amount];

        // Take the current coin
        int take = solve(coins, amount - coins[i], i);

        if (take != INT_MAX)
            take = 1 + take;

        // Skip the current coin
        int skip = solve(coins, amount, i + 1);

        return dp[i][amount] = min(take, skip);
    }

    int coinChange(vector<int>& coins, int amount) {

        dp.assign(coins.size(), vector<int>(amount + 1, -1));

        int ans = solve(coins, amount, 0);

        return (ans == INT_MAX) ? -1 : ans;
    }
};