class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int curMax = nums[0];
        int curMin = nums[0];
        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++) {

            int a = nums[i];
            int b = curMax * nums[i];
            int c = curMin * nums[i];

            int newMax = max({a, b, c});
            int newMin = min({a, b, c});

            curMax = newMax;
            curMin = newMin;

            ans = max(ans, curMax);
        }

        return ans;
    }
};