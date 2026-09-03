class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.size();
        int left = 0;
        int right = 0;
        vector<int> mp(256, -1);
        int maxLen = 0;

        while(right < n){

            if(mp[s[right]] != -1){
                if(left <= mp[s[right]]){
                    left = mp[s[right]] + 1;
                }
            }

            maxLen = max(maxLen, right - left + 1);
            mp[s[right]] = right;
            right++;
        }

        return maxLen;
    }
};
