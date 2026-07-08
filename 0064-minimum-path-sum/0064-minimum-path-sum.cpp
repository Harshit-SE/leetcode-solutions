class Solution {
public:
    int m, n;
    vector<vector<int>> dp;

    int solve(vector<vector<int>>& grid, int i, int j) {
        if (dp[i][j] != -1)
            return dp[i][j];

        if (i == m - 1 && j == n - 1) {
            return dp[i][j] = grid[i][j];
        }

        if (i == m - 1) {
            return dp[i][j] = solve(grid, i, j + 1) + grid[i][j];
        }

        if (j == n - 1) {
            return dp[i][j] = solve(grid, i + 1, j) + grid[i][j];
        }

        return dp[i][j] = grid[i][j] +
                          min(solve(grid, i + 1, j),
                              solve(grid, i, j + 1));
    }

    int minPathSum(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        dp.assign(m, vector<int>(n, -1));

        return solve(grid, 0, 0);
    }
};