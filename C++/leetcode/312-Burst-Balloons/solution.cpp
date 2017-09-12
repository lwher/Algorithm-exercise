class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size() + 2;
        vector<int> newNums;
        newNums.push_back(1);
        for (int i = 0; i < nums.size(); ++i) {
            newNums.push_back(nums[i]);
        }
        newNums.push_back(1);
        vector<vector<int> > dp(n);
        for (int i = 0; i < n; ++i) {
            dp[i].resize(n);
        }
        if (n == 2) return 0;
        for (int l = 3; l <= n; ++l) {
            for (int i = 0; i < n - l + 1; ++i) {
                int j = i + l - 1;
                for (int k = i + 1; k < j; ++k) {
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + newNums[i] * newNums[j] * newNums[k]);
                }
            }
        }
        return dp[0][n - 1];
    }
};

