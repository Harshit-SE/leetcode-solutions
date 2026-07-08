class Solution {
public:
    vector<vector<int>> dp;

    int solve(vector<int>& coins, int amount, int i) {

        // Found one valid way
        if (amount == 0)
            return 1;

        // Invalid path
        if (amount < 0 || i == coins.size())
            return 0;

        if (dp[i][amount] != -1)
            return dp[i][amount];

        // Take current coin (stay at same index because coins are unlimited)
        int take = solve(coins, amount - coins[i], i);

        // Skip current coin
        int skip = solve(coins, amount, i + 1);

        return dp[i][amount] = take + skip;
    }

    int change(int amount, vector<int>& coins) {

        dp.assign(coins.size(), vector<int>(amount + 1, -1));

        return solve(coins, amount, 0);
    }
};