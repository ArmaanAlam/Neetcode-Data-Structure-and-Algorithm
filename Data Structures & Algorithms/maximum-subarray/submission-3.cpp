class Solution {

    int solve(vector<int>& nums, int index, vector<int>& dp) {

        if(index == 0) {
            dp[0] = nums[0];
            return dp[0];
        }

        dp[index] = max(nums[index],
                        solve(nums, index - 1, dp) + nums[index]);

        return dp[index];
    }

public:
    int maxSubArray(vector<int>& nums) {

        int n = nums.size();
        vector<int> dp(n);

        solve(nums, n - 1, dp);

        int ans = *max_element(dp.begin(), dp.end());

        return ans;
    }
};