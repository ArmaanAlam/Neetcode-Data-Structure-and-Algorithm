class Solution:
    def isPalindrome(self, s: str) -> bool:
        
        test = ""

        for char in s:
            if char.isalnum():
                test += char.lower()
        
        left = 0
        right = len(test) - 1

        while left < right:
            if test[left] != test[right]:
                return False
            left += 1
            right -= 1
        
        return True