class Solution:
    def firstUniqChar(self, s: str) -> int:

        mp = {}

        for char in s:
            mp[char] = mp.get(char, 0) + 1

        i = 0

        for char in s:
            if mp[char] == 1:
                return i
            i += 1
        
        return -1


        

        