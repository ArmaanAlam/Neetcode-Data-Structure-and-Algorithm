class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        
        int right = k-1;
        int left = 0;
        int res = INT_MAX;
        sort(nums.begin(), nums.end());

        while(right < nums.size()){
            res = min(res, nums[right] - nums[left]);
            right++;
            left++;
        }

        return res;
    }
};