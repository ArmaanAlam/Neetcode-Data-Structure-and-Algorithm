class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        
        int n = order.size();
        int m = words.size();
        unordered_map<char, int> mp;

        for(int i = 0; i < n; i++){
            mp[order[i]] = i;
        }
        
        for(int i = 0; i < m-1; i++){
            string s1 = words[i];
            string s2 = words[i+1];

            int len = min(s1.size(), s2.size());
            bool decided = false;

            for(int j = 0; j < len; j++){
                if (s1[j] != s2[j]) {
        if (mp[s1[j]] > mp[s2[j]]) {
            return false;
        }

        decided = true;
        break;
    }
            }

            if (!decided && s1.size() > s2.size()) {
                return false;
            }

        }

        return true;
    }
};