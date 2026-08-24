class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int n = strs.size();

        sort(strs.begin(), strs.end());

        string first = strs[0];
        string end = strs[n-1];

        string ans = "";

        for(int i = 0; i < first.size(); i++){
            if(first[i] != end[i]){
                return ans;
            }
            ans += first[i];
        }

        return ans;
    }
};