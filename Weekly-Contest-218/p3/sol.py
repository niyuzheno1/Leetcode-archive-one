 def concatenatedBinary( n: int) -> int:
        modn = 1000000007
        ans = 0
        for i in range(1,n+1):
            for j in range(30,-1,-1):
                if (i & (1 << j)):
                    ans = (ans * pow(2, j+1, modn)) % modn
                    ans += i
        return ans

concatenatedBinary(3)