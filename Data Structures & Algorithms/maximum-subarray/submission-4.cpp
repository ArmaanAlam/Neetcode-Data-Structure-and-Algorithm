class Solution {

    void solve(vector<int>& nums, int index, vector<int>& dp) {

        if(index == nums.size())
            return;

        if(index == 0)
            dp[index] = nums[index];
        else
            dp[index] = max(nums[index],
                             nums[index] + dp[index - 1]);

        solve(nums, index + 1, dp);
    }

public:
    int maxSubArray(vector<int>& nums) {

        int n = nums.size();
        vector<int> dp(n);

        solve(nums, 0, dp);

        return *max_element(dp.begin(), dp.end());
    }
};