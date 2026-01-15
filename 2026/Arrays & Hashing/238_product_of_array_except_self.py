class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        # First pass for the prefix sum
        res = [1] * len(nums)
        prefix = 1
        
        # Forward Pass to populate Prefixes
        #for i in range(len(nums)):
        #    res[i] = num[i] * prefix
        #    prefix = res[i]
        for i in range(len(nums)):
            res[i] = prefix
            prefix *= nums[i]

        postfix = 1

        # Backward Pass to populate postfixes
        for i in range(len(nums)-1,-1,-1):
            res [i] *= postfix # Multiplying the prefix for that index to the postfix for that index. *= to prevent overwriting the prefixes already in res
            postfix *= nums[i]

        # res now has all the required outputs

        return res



            

        