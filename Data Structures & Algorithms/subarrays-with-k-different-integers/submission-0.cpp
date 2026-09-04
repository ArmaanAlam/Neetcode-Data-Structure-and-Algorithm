class Solution {

    int atMostK(vector<int>& nums, int k){

        int n = nums.size();
        int left = 0;
        int right = 0;
        int cnt = 0;
        unordered_map<int, int> mp;

        while(right < n){

            mp[nums[right]]++;

            while(mp.size() > k){
                mp[nums[left]]--;

                if(mp[nums[left]] == 0){
                    mp.erase(nums[left]);
                }

                left++;
            }

            cnt += right - left + 1;
            right++;
        }

        return cnt;
    }
    
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};