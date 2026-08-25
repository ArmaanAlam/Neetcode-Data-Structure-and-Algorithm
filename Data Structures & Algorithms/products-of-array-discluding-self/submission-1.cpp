class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int zero = 0;
        int product = 1;
        int n = nums.size();

        for(int num : nums){
            if(num != 0){
                product *= num;
            }
            else{
                zero++;
            }
        }

        if(zero > 1){
            return vector<int>(n, 0);
        }

        vector<int> ans(n);

        for(int i = 0; i < n; i++){
            if(zero > 0){
                if(nums[i] == 0){
                    ans[i] = product;
                }
                else{
                    ans[i] = 0;
                }
            }
            else{
                ans[i] = product / nums[i];
            }
        }

        return ans;
    }
};
