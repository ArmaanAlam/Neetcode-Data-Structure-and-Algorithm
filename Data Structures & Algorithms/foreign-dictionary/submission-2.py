
from collections import deque
from typing import List

class Solution:
    def foreignDictionary(self, words: List[str]) -> str:
        adj = [[] for _ in range(26)]
        present = [False] * 26
        total = 0

        for word in words:
            for char in word:
                idx = ord(char) - ord('a')
                if not present[idx]:
                    present[idx] = True
                    total += 1

        for i in range(len(words) - 1):
            s1 = words[i]
            s2 = words[i + 1]

            minLen = min(len(s1), len(s2))
            found = False

            for j in range(minLen):
                if s1[j] != s2[j]:
                    u = ord(s1[j]) - ord('a')
                    v = ord(s2[j]) - ord('a')
                    adj[u].append(v)
                    found = True
                    break
            if not found and len(s1) > len(s2):
                return ""

        indegree = [0] * 26

        for u in range(26):
            for node in adj[u]:
                indegree[node] += 1

        q = deque()

        for i in range(26):
            if present[i] and indegree[i] == 0:
                q.append(i)

        ans = []

        while q:
            node = q.popleft()
            ans.append(chr(node + ord('a')))

            for adjnode in adj[node]:
                indegree[adjnode] -= 1

                if indegree[adjnode] == 0:
                    q.append(adjnode)

        if len(ans) != total:
            return ""

        return "".join(ans)
