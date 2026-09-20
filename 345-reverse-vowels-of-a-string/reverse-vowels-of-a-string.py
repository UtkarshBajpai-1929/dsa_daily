class Solution:
    def isVowel(self, c: str) -> bool:
        if c == 'a' or c == 'e' or c == 'i' or c=='o' or c=='u' or c=='A' or c=='E' or c=='I' or c=='O' or c=='U':
            return True
        return False
    def reverseVowels(self, s: str) -> str:
        a = list(s)
        i = 0
        j = len(a)-1
        while i < j:
            while i<j and not self.isVowel(a[i]):
                i+=1
            while i<j and not self.isVowel(a[j]):
                j-=1
            a[i], a[j] = a[j], a[i]
            i+=1
            j-=1
        s = "".join(a)
        return s
