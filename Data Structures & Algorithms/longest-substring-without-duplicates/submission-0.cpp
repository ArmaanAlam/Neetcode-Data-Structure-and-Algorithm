class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int right = 0;
        int left = 0;
        unordered_set<int> st;
        int maxLen = 0;

        while(right < n){

            while(st.count(s[right])){
                st.erase(s[left]);
                left++;
            }

            st.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;
    }
};
