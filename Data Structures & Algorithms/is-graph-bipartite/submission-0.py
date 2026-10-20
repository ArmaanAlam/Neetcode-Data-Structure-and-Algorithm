
from collections import deque

class Solution:

    def BFS(self, graph, color, i):
        color[i] = 0
        q = deque([i])

        while q:
            node = q.popleft()

            for adjnode in graph[node]:
                if color[adjnode] == -1:
                    color[adjnode] = 1 - color[node]
                    q.append(adjnode)

                elif color[adjnode] == color[node]:
                    return False

        return True
    

    def DFS(self, graph, color, node):

        for adjnode in graph[node]:

            if color[adjnode] == -1:
                color[adjnode] = 1 - color[node]

                if not self.DFS(graph, color, adjnode):
                    return False

            elif color[adjnode] == color[node]:
                return False

        return True


    def isBipartite(self, graph: list[list[int]]) -> bool:
        n = len(graph)
        color = [-1] * n

        for i in range(n):
            if color[i] == -1:
                if not self.DFS(graph, color, i):
                    return False

        return True
