from collections import deque

class Solution:
    def eventualSafeNodes(self, graph: list[list[int]]) -> list[int]:
        
        V = len(graph)
        indegree = [0]*V
        q = deque()
        adj = [[] for _ in range(V)]
        ans = []

        for u in range(V):
            for v in graph[u]:
                adj[v].append(u)
        

        for u in range(V):
            for v in adj[u]:
                indegree[v] += 1
        
        for i in range(V):
            if indegree[i] == 0:
                q.append(i)
        

        while q:
            node = q[0]
            q.popleft()
            ans.append(node)
            for adjnode in adj[node]:
                indegree[adjnode] -= 1
                if indegree[adjnode] == 0:
                    q.append(adjnode)
        
        ans.sort()

        return ans