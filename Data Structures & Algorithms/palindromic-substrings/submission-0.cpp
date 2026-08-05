class Solution {

    int count(string &s, int i, int j){

        int n = s.size();
        int cnt = 0;
        while(i >= 0 && j < n && s[i] == s[j]){
            cnt++;
            i--;
            j++;
        }

        return cnt;
    }

public:
    int countSubstrings(string s) {
        
        int n = s.size();
        int cnt = 0;
        for(int i = 0; i < n; i++){
            int oddcount = count(s, i, i);
            cnt += oddcount;
            int evencount = count(s, i, i+1);
            cnt += evencount;
        }
        return cnt;
    }
};
