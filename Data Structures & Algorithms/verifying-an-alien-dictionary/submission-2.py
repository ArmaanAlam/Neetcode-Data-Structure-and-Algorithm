class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        
        n = len(order)
        m = len(words)

        mp = {}

        for i, ch in enumerate(order):
            mp[ch] = i
        

        for i in range(m-1):
            s1 = words[i]
            s2 = words[i+1]

            minLen = min(len(s1), len(s2))
            decide = False

            for j in range(minLen):
                if s1[j] != s2[j]:
                    if mp[s1[j]] > mp[s2[j]]:
                        return False
                    
                    decide = True
                    break
            
            if(not decide and len(s1) > len(s2)):
                return False
        
        return True



