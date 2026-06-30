class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> dp(n + 1);

        dp[1] = nums[0];          
        int maxi = dp[1];

        for (int i = 2; i <= n; i++) {
            dp[i] = max(nums[i - 1], dp[i - 1] + nums[i - 1]);
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};