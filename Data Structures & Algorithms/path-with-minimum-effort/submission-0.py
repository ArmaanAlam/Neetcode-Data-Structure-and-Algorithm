class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:

        n = len(heights)
        m = len(heights[0])

        distance = [[float('inf')] * m for _ in range(n)]
        q = deque()
        q.append([0, 0, 0])
        distance[0][0] = 0

        dr = [-1, 0, 1, 0]
        dc = [0, -1, 0, 1]

        while q:
            d = q[0][0]
            r = q[0][1]
            c = q[0][2]
            q.popleft()

            for i in range(4):
                row = r + dr[i]
                col = c + dc[i]

                if(row >= n or col >= m or row < 0 or col < 0):
                    continue
                
                dt = max(d, abs(heights[row][col] - heights[r][c]))

                if(dt < distance[row][col]):
                    distance[row][col] = dt
                    q.append([dt, row, col])
        
        return distance[n-1][m-1]





