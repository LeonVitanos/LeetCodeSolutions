#Runtime: 43 ms, faster than 56.05% of Python3 online submissions for Reverse Integer.

class Solution:
    def reverse(self, x: int) -> int:
        neg = True if x<0 else False 
        temp = str(x)[1:][::-1] if neg else str(x)[::-1]

        try:
            num = int(temp)
            if num<-2147483648 or num>2147483647: # outside the signed 32-bit integer range [-2^31, 2^31 - 1]
                return 0
            return num*(-1) if neg else num
        except:
            return 0

a = Solution()
print(a.reverse(123))
print(a.reverse(-123))
print(a.reverse(1534236469))