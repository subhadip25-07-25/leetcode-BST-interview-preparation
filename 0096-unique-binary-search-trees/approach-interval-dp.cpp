class Solution {
public:
    vector<vector<int>> dp;

    int solve(int st, int end) {
        if (st > end) return 1;
        if (dp[st][end] != -1) return dp[st][end];

        int total = 0;
        for (int i = st; i <= end; i++) {
            int leftSubtree = solve(st, i - 1);
            int rightSubtree = solve(i + 1, end);
            total += leftSubtree * rightSubtree;
        }
        return dp[st][end] = total;
    }

    int numTrees(int n) {
        dp.assign(n + 2, vector<int>(n + 2, -1));
        return solve(1, n);
    }
};