
class Solution:

    def minReorder(self, n: int, connections: List[List[int]]) -> int:

        # Build adjacency list
        adj = [[] for _ in range(n)]

        for u, v in connections:
            adj[u].append([v, 1])
            adj[v].append([u, 0])

        visit = [False] * n

        # DFS using stack
        stack = [0]
        visit[0] = True

        count = 0

        while stack:

            node = stack.pop()

            for adjnode, direction in adj[node]:

                if not visit[adjnode]:

                    count += direction

                    visit[adjnode] = True
                    stack.append(adjnode)

        return count
