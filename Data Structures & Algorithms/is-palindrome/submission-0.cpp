class Solution {
public:
    bool isPalindrome(string s) {
        string temp;
        for(char ch : s){
            if(isalnum(ch)) {
                temp += tolower(ch);
            }
        }

        int n = temp.size();

        int left = 0;
        int right = n-1;

        while(left < right){
            if(temp[left] != temp[right]){
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};
