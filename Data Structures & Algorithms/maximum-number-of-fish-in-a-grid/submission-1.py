from collections import deque
from typing import List
class Solution:

    def isValid(self, grid, visit, row, col):
        n = len(grid)
        m = len(grid[0])

        return row < n and col < m and row >= 0 and col >= 0 and not visit[row][col] and grid[row][col] > 0
        

    def DFS(self, grid, visit, i, j):

        q = deque()
        q.append([i, j])
        visit[i][j] = True
        count = 0

        dr = [-1, 0, 1, 0]
        dc = [0, -1, 0, 1]

        while q:
            r = q[0][0]
            c = q[0][1]
            q.popleft()

            count += grid[r][c]

            for i in range(4):

                row = r + dr[i]
                col = c + dc[i]

                if(self.isValid(grid, visit, row, col)):
                    q.append([row, col])
                    visit[row][col] = True
        
        return count
    def findMaxFish(self, grid: List[List[int]]) -> int:
        
        n = len(grid)
        m = len(grid[0])

        visit = [[False]*m for _ in range(n)]

        ans = 0

        for i in range(n):
            for j in range(m):
                if grid[i][j] != 0 and not visit[i][j]:
                    temp = self.DFS(grid, visit, i, j)
                    ans = max(temp, ans)

        return ans




        
    