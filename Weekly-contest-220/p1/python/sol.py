class Solution:
    def reformatNumber(self, number: str) -> str:
        n = number.replace('-', '').replace(' ', '')
        m = len(n)
        if m % 3 == 0:
            ans = ""
            for i in range(0,m//3):
                ans += n[3*i] + n[3*i+1] + n[3*i+2]
                ans += "-"
            return ans[:len(ans)-1]
        elif m % 3 == 1:
            ans = ""
            m = m - 1
            m = m - 3
            for i in range(0,m//3):
                ans += n[3*i] + n[3*i+1] + n[3*i+2]
                ans += "-"
            ans +=  n[-4]+n[-3]
            ans += "-" + n[-2]+n[-1]
            return ans
        else:
            ans = ""
            m = m - 2
            for i in range(0,m//3):
                ans += n[3*i] + n[3*i+1] + n[3*i+2]
                ans += "-"
            ans +=  n[-2]+n[-1]
            return ans