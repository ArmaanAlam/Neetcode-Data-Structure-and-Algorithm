class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<int> ans;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            int remain = target - nums[i];

            if(mp.find(remain) != mp.end()){
                ans.push_back(mp[remain]);
                ans.push_back(i);
                return ans;
            }
            mp[nums[i]] = i;
        }

        return ans;
    }
};
