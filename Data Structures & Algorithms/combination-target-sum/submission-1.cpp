class Solution {

    void solve(vector<int>& nums, int target, int i, vector<int>& curr, vector<vector<int>> &res){

        if(target == 0){
            res.push_back(curr);
            return;
        }

        if(target < 0 || i >= nums.size()){
            return;
        }

        curr.push_back(nums[i]);
        solve(nums, target - nums[i], i, curr, res);
        curr.pop_back();

        solve(nums, target, i+1, curr, res);

    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        solve(nums, target, 0, curr, res);
        return res;
    }
};
