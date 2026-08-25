class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);

        for(int i = 1; i < n; i++){
            prefix[i] = nums[i-1] * prefix[i-1];
        }

        for(int i = n-2; i >= 0; i--){
            suffix[i] = nums[i+1] * suffix[i+1];
        }

        vector<int> ans;
        for(int i = 0; i < n; i++){
            ans.push_back(prefix[i]*suffix[i]);
        }

        return ans;
    }
};
