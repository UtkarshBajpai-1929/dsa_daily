class Solution:
    def reverseDegree(self, s: str) -> int:
        mp = {}
        ch = "abcdefghijklmnopqrstuvwxyz"
        for c in ch:
            mp[c] = 26 - (ord(c) - ord('a'))
        ans = 0
        for i in range(len(s)):
            ans += (mp[s[i]]*(i+1))
        return ans
