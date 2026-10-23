class Solution:
    def countServers(self, grid: List[List[int]]) -> int:

        n = len(grid)
        m = len(grid[0])

        row = [0]*n
        col = [0]*m

        for i in range(n):
            for j in range(m):
                if grid[i][j]:
                    row[i] += 1
                    col[j] += 1
        

        count = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1 and (row[i] > 1 or col[j] > 1):
                    count += 1
        
        return count
        