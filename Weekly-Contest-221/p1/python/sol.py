class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        n = len(s)
        halves = n//2
        first = 0
        second = 0
        for i in range(0,halves):
            if s[i] in ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']:
                first = first + 1
        s =  s[::-1]
        for i in range(0,halves):
            if s[i] in ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']:
                second = second + 1
        return first == second
            