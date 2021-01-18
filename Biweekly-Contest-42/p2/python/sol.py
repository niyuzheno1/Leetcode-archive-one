class Solution:
    def averageWaitingTime(self, customers: List[List[int]]) -> float:
        c_time = 0
        n = len(customers)
        u = [0]*n
        for i in range(0,n):
            if customers[i][0] > c_time:
                c_time = customers[i][0] + customers[i][1]
                u[i] = customers[i][1]
            else:
                c_time = c_time + customers[i][1]
                u[i] = c_time - customers[i][0]
        return sum(u)/n