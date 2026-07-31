class Solution {
public:
    int solve(int index, vector<int>& nums, vector<int>& dp, int n) {
        if (index >= n)
            return 0;

        if (dp[index] != -1)
            return dp[index];

        int take = nums[index] + solve(index + 2, nums, dp, n);
        int notTake = solve(index + 1, nums, dp, n);

        return dp[index] = max(take, notTake);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        vector<int> dp1(n, -1);
        int case1 = solve(0, nums, dp1, n - 1);

        vector<int> temp(nums.begin() + 1, nums.end());
        vector<int> dp2(temp.size(), -1);
        int case2 = solve(0, temp, dp2, temp.size());

        return max(case1, case2);
    }
};