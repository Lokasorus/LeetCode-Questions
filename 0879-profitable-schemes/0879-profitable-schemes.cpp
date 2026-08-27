class Solution {
    int MOD = 1e9 + 7;
    int memo[101][101][101];

    int f(int i, int profi, int cnt, int minProfit, int n, vector<int>& group, vector<int>& profit) {
        // Capping profit at minProfit keeps the state space within array bounds
        profi = min(profi, minProfit);

        // Base case: processed all crimes
        if (i == group.size()) {
            return profi >= minProfit ? 1 : 0;
        }

        if (memo[i][profi][cnt] != -1) {
            return memo[i][profi][cnt];
        }

        // Option 1: Do not take the current crime
        int nottake = f(i + 1, profi, cnt, minProfit, n, group, profit);

        // Option 2: Take the current crime (if enough group members are available)
        int take = 0;
        if (cnt + group[i] <= n) {
            take = f(i + 1, profi + profit[i], cnt + group[i], minProfit, n, group, profit);
        }

        return memo[i][profi][cnt] = (nottake + take) % MOD;
    }

public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(memo, -1, sizeof(memo));
        return f(0, 0, 0, minProfit, n, group, profit);
    }
};