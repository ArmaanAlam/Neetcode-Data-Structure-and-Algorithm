class Solution:
    def findChampion(self, n: int, edges: List[List[int]]) -> int:

        indegree = [0]*n
        ans = []

        for u, v in edges:
            indegree[v] += 1

        for i in range(n):
            if indegree[i] == 0:
                ans.append(i)

        return ans[0] if len(ans) == 1 else -1
        