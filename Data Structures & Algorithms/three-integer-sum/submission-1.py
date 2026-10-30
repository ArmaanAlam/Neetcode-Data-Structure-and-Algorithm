class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:

        nums.sort()
        n = len(nums)
        ans = []

        for i in range(n):
            if i != 0 and nums[i] == nums[i-1]:
                continue
            
            j = i+1
            k = n-1

            while(j < k):
                num = nums[i] + nums[j] + nums[k]
                if(num > 0):
                    k -= 1
                elif(num < 0):
                    j += 1
                else:
                    ans.append([nums[i], nums[j], nums[k]])
                    k -= 1
                    j += 1

                    while(j < k and nums[j] == nums[j-1]):
                        j += 1
                    while(k > j and nums[k] == nums[k+1]):
                        k -= 1
        
        return ans

        