class Solution:

    def DFS(self, adj, visit, node, parent) -> bool:

        visit[node] = True

        for adjnode in adj[node]:
            if(not visit[adjnode]):
                if not self.DFS(adj, visit, adjnode, node):
                    return False
            elif parent != adjnode:
                return False

        return True

    def validTree(self, n: int, edges: List[List[int]]) -> bool:

        adj = [[] for _ in range(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        
        visit = [False]*n

        if not self.DFS(adj, visit, 0, -1):
            return False
        
        for i in range(n):
            if not visit[i]:
                return False
        
        return True
        