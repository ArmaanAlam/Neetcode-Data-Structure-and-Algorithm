class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dpMin(n);
        vector<int> dpMax(n);
        dpMax[0] = nums[0];
        dpMin[0] = nums[0];
        int ans = nums[0];

        for(int i = 1; i < n; i++){
            int a = nums[i];
            int b = dpMax[i - 1] * nums[i];
            int c = dpMin[i - 1] * nums[i];

            dpMax[i] = max({a, b, c});
            dpMin[i] = min({a, b, c});

            ans = max(ans, dpMax[i]);

        }

        return ans;
    }
};
