from collections import deque
from typing import List

class Solution:

    def BFS(self, adj, visit, node):
        q = deque()
        q.append(node)
        visit[node] = 1

        while q:
            node = q.popleft()

            for adjnode in adj[node]:
                if visit[adjnode] == 0:
                    visit[adjnode] = 1
                    q.append(adjnode)

    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        count = 0
        visit = [0] * n

        adj = [[] for _ in range(n)]

        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        for i in range(n):
            if visit[i] == 0:
                count += 1
                self.BFS(adj, visit, i)

        return count