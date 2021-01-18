class Solution:
    def maximumBinaryString(self, binary: str) -> str:
        zeros = 0 
        ones = 0 
        leadingones = 0
        flag = True
        n = len(binary)
        for i in range(0, n):
            if binary[i] == '0':
                flag = False
                zeros = zeros + 1
            else:
                if flag:
                    leadingones = leadingones + 1
                ones = ones + 1
        a = (leadingones) * '1' + (zeros-1)*"1" + ('0' if zeros >= 1 else '') + (ones-leadingones )* '1'
        return a

u = Solution()
print(u.maximumBinaryString("1110"))