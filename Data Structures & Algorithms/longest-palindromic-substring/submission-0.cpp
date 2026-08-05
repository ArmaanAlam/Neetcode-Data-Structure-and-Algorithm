class Solution {

    void palindromic(string &s, int left, int right, int &start, int &maxLen){

        int n = s.size();
        while(left >= 0 && right < n && s[left] == s[right]){
            if(right - left + 1 > maxLen){
                maxLen = right - left + 1;
                start = left;
            }
            left--;
            right++;
        }
    }

public:
    string longestPalindrome(string s) {
        
        int n = s.size();
        int maxLen = 0;
        int start;
        for(int i = 0; i < n; i++){
            palindromic(s, i, i, start, maxLen);
            palindromic(s, i, i+1, start, maxLen);
        }
        string ans = s.substr(start, maxLen);

        return ans;
    }
};
