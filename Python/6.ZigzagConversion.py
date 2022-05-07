#Runtime: 63 ms, faster than 81.26% of Python3 online submissions for Zigzag Conversion.

class Solution:
    def convert(self, s: str, numRows: int) -> str:
        posHor = 0
        posVer = 0

        if numRows == 1:
            return s

        table = []
        for i in range(0, numRows):
            table.append("")

        for c in s:
            if posHor%(numRows-1) == 0:

                table[posVer] += c
                if posVer==(numRows-1):
                    posHor += 1
                    posVer = 0
                else:
                    posVer += 1
            else:
                table[-posVer-2] += c
                posHor += 1
                posVer = 0 if posHor%(numRows-1) == 0 else posVer + 1

        output = ""
        for i in range(0, numRows):
            output += table[i]

        return output

a = Solution()
print(a.convert("PAYPALISHIRING", 3))
print(a.convert("PAYPALISHIRING", 4))
print(a.convert("A", 1))