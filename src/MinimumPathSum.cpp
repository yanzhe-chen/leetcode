#include "MinimumPathSum.hpp"

using namespace std;

int MinimumPathSum::minPathSum(vector<vector<int>> &grid) {
    int m = grid.size();

    if (m == 0) return 0;

    int n = grid[0].size();

    if (n == 0) return 0;

    vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
    dp[0][0] = grid[0][0];

    for (int i = 1; i < m; i++)
        dp[i][0] = dp[i - 1][0] + grid[i][0];

    for (int j = 1; j < n; j++)
        dp[0][j] = dp[0][j - 1] + grid[0][j];

    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];

    return dp[m - 1][n - 1];
}

