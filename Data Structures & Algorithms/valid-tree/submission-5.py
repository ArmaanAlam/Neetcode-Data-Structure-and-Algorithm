class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:

        adj = [[] for _ in range(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

        visit = [False]*n
        q = deque()
        q.append([0, -1])
        visit[0] = True

        while q:
            node = q[0][0]
            parent = q[0][1]
            q.popleft()

            for adjnode in adj[node]:
                if not visit[adjnode]:
                    q.append([adjnode, node])
                    visit[adjnode] = True
                else:
                    if parent != adjnode:
                        return False
        
        for i in range(n):
            if not visit[i]:
                return False
        
        return True
        