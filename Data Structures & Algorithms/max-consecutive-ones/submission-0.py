class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        
        n = len(nums)

        maxLen = 0;
        cnt = 0

        for num in nums:
            if(num == 1):
                cnt += 1
                maxLen = max(maxLen, cnt)
            else:
                cnt = 0
        
        return maxLen