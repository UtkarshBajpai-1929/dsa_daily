class Solution:
    def missingNumber(self, nums: list[int]) -> int:
        n = len(nums) + 1
        req_sum = int((n *(n-1))/2)
        s = 0
        for x in nums:
            s+=x
        return req_sum - s
