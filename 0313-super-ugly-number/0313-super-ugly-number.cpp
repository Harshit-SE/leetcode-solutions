class Solution {
public:
    vector<long long> dp;
    vector<int> idx;
    vector<int> primes;

    void solve(int pos) {

        if (pos == dp.size())
            return;

        long long next = LLONG_MAX;

        // Find the next super ugly number
        for (int j = 0; j < primes.size(); j++) {
            next = min(next, dp[idx[j]] * primes[j]);
        }

        dp[pos] = next;

        // Move all pointers which generated next
        for (int j = 0; j < primes.size(); j++) {
            if (dp[idx[j]] * primes[j] == next) {
                idx[j]++;
            }
        }

        solve(pos + 1);
    }

    int nthSuperUglyNumber(int n, vector<int>& p) {

        primes = p;

        dp.resize(n);
        idx.assign(primes.size(), 0);

        dp[0] = 1;

        solve(1);

        return dp[n - 1];
    }
};