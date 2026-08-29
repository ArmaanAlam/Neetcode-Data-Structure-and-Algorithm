class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        int n = word1.size();
        int m = word2.size();

        string ans;

        int i = 0;
        int j = 0;

        while(i < n && j < m){
            ans += word1[i];
            ans += word2[j];
            i++;
            j++;
        }

        while(i < n){
            ans += word1[i];
            i++;
        }

        while(j < m){
            ans += word2[j];
            j++;
        }

        return ans;
    }
};