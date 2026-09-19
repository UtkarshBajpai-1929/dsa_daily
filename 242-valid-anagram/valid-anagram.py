class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        freq = [0]*26
        for i in range(len(s)):
            freq[ord(s[i]) - ord('a')] += 1
        for i in range(len(t)):
            freq[ord(t[i]) - ord('a')] -= 1
        ans = True
        for i in range(len(freq)):
            if freq[i] != 0:
                ans = False
                break
        return ans
