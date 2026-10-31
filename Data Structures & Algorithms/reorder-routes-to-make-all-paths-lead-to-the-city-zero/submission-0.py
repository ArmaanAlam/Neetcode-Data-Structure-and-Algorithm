class Solution:
    def minReorder(self, n: int, connections: List[List[int]]) -> int:

        adj = [[] for _ in range(n)]
        visit = [False]*n

        for u, v in connections:
            adj[u].append([v, 1])
            adj[v].append([u, 0])

        count = 0
        q = deque()
        q.append(0)
        visit[0] = True

        while q:
            node = q[0]
            q.popleft()

            for adjnode, dir in adj[node]:
                if not visit[adjnode]:
                    count += dir
                    q.append(adjnode)
                    visit[adjnode] = True
        
        return count
        
        