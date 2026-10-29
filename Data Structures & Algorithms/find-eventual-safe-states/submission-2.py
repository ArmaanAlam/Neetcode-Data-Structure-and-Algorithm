from collections import deque

class Solution:
    def eventualSafeNodes(self, graph: list[list[int]]) -> list[int]:
        V = len(graph)

        reverse = [[] for _ in range(V)]
        outdegree = [0] * V

        for node in range(V):
            outdegree[node] = len(graph[node])

            for adjnode in graph[node]:
                reverse[adjnode].append(node)

        q = deque()

        for i in range(V):
            if outdegree[i] == 0:
                q.append(i)

        safe = []

        while q:
            node = q.popleft()
            safe.append(node)

            for prev in reverse[node]:
                outdegree[prev] -= 1

                if outdegree[prev] == 0:
                    q.append(prev)

        return sorted(safe)