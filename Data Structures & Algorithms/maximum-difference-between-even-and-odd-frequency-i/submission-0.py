class Solution:
    def maxDifference(self, s: str) -> int:

        mp = {}
        for ch in s:
            mp[ch] = mp.get(ch, 0) + 1

        odd = 0
        even = float('inf')
        
        for key, value in mp.items():
            if(value % 2):
                odd = max(odd, value)
            else:
                even = min(even, value)
            
        return odd - even
        