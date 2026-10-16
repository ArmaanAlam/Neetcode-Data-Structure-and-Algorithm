from typing import List

class Solution:

    def DFS(self, adj, visit, node):
        visit[node] = 1

        for adjnode in adj[node]:
            if visit[adjnode] == 0:
                self.DFS(adj, visit, adjnode)

    def countComponents(self, n: int, edges: List[List[int]]) -> int:

        visit = [0] * n
        adj = [[] for _ in range(n)]

       
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        count = 0

        
        for i in range(n):
            if visit[i] == 0:
                count += 1
                self.DFS(adj, visit, i)

        return count