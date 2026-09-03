class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int prefix = 1;
        int suffix = 1;
        int ans = INT_MIN;

        for(int i = 0; i < nums.size(); i++){

            prefix *= nums[i];
            ans = max(ans, prefix);
            if(prefix == 0){
                prefix = 1;
            }

            suffix *= nums[nums.size()-1-i];
            ans = max(ans, suffix);
            if(suffix == 0){
                suffix = 1;
            }

        }
        return ans;
    }
};