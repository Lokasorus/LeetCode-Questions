class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        // 1. MUST SORT FIRST
        sort(stones.begin(), stones.end());
        int n = stones.size();

        // 2. Maximum moves calculation
        int maxi = max(stones[n - 1] - stones[1], stones[n - 2] - stones[0]) - (n - 2);

        int mini = n;
        int i = 0;

        for (int j = 0; j < n; j++) {
            // Fix: Change '>= n' to '> n'
            while (stones[j] - stones[i] + 1 > n) {
                i++;
            }

            int count = j - i + 1;

            if (count == n - 1 && stones[j] - stones[i] == n - 2) {
                mini = min(mini, 2);
            } else {
                mini = min(mini, n - count);
            }
        }

        return {mini, maxi};
    }
};