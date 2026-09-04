class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        int pref = 0;
        int cnt = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;

        for(int i = 0; i < n; i++){
            pref += nums[i];

            int remain = pref - k;

            if(mp.find(remain) != mp.end()){
                cnt += mp[remain];
            }

            mp[pref]++;
        }

        return cnt;
    }
};