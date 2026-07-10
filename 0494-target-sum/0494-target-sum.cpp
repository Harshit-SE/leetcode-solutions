class Solution {
public:
    unordered_map<string, int> dp;

    int solve(vector<int>& nums, int target, int i) {

        if (i == nums.size()) {
            return target == 0;
        }

        string key = to_string(i) + "#" + to_string(target);

        if (dp.find(key) != dp.end()) {
            return dp[key];
        }

        int plus = solve(nums, target - nums[i], i + 1);

        int minus = solve(nums, target + nums[i], i + 1);

        return dp[key] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        return solve(nums, target, 0);
    }
};