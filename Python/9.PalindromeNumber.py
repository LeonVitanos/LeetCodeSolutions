class Solution:
    def isPalindrome(self, x: int) -> bool:
            s = str(x)
            pos = 0
            for x in s[:(int)(len(s)/2)]:
                if s[pos] != s[-pos-1]:
                    return False
                pos += 1
            return True

a = Solution()
print(a.isPalindrome(12121))
