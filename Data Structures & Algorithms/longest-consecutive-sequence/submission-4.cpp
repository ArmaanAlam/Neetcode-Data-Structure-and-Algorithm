class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size();

        if(n == 0) return 0;

        sort(nums.begin(), nums.end());

        int cnt = 1;
        int maxLen = 1;

        for(int i = 1; i < n; i++){
            if(nums[i-1] == nums[i]){
                continue;
            }

            if(nums[i-1] + 1 == nums[i]){
                cnt++;
                maxLen = max(maxLen, cnt);
            }
            else{
                cnt = 1;
            }

        }

        return maxLen;
    }
};
