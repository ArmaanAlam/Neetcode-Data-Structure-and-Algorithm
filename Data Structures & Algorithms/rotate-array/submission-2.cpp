class Solution {

    void solve(vector<int> &nums, int start, int end){
        while(start < end){
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
        return;
    }

public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        k = k % n;

        solve(nums, 0, n-k-1);
        solve(nums, n-k, n-1);
        solve(nums, 0, n-1);

        return;
    }
};