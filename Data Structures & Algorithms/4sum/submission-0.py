class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:

        n = len(nums)
        nums.sort()
        ans = []

        for i in range(n):
            if i != 0 and nums[i] == nums[i-1]:
                continue
            for j in range(i+1, n):
                if j > i+1 and nums[j] == nums[j-1]:
                    continue
                
                k = j+1
                l = n-1

                while(k < l):
                    num = nums[i] + nums[j] + nums[k]
                    num += nums[l]

                    if num > target:
                        l -= 1
                    elif num < target:
                        k += 1
                    else:
                        ans.append([nums[i], nums[j], nums[k], nums[l]])
                        k += 1
                        l -= 1

                        while(k < l and nums[k] == nums[k-1]):
                            k += 1
                        
                        while(l > k and nums[l] == nums[l+1]):
                            l -= 1
        
        return ans
        