class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int n = haystack.size();
        int m = needle.size();

        for(int i = 0; i < n; i++){

            int index = 0;
            int j = i;

            while(j < n && index < m && haystack[j] == needle[index]){
                j++;
                index++;
            }

            if(index == m){
                return i;
            }
        }

        return -1;
    }
};