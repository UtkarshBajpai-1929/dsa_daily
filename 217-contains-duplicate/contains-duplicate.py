class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        m = {}
        for x in nums:
            m[x] = m.get(x, 0) + 1 
        for key, value in m.items():
            if value >= 2:
                return True
        return False