from collections import defaultdict  
class Solution(object):
    def findSubstring(self, s, words):
        res = []
        dictionary = defaultdict(int)  
        ls = len(s)
        lstr = len(words[0])
        wgs = len(words)
        if ls == 0:
            return []
        for y in words:
            dictionary[y] += 1
        for x in range(lstr):
            size = defaultdict(int)  
            l = x 
            gs = 0
            for y in range(x, ls, lstr):
                t = s[y : y + lstr]
                if t in dictionary:
                    size[t] += 1
                    if size[t] <= dictionary[t]:
                        gs += 1
                    while not s[l : l + lstr] in dictionary or size[s[l : l + lstr]] > dictionary[s[l : l + lstr]]:
                        if s[l : l + lstr] in dictionary:
                            size[s[l : l + lstr]] -= 1
                        l += lstr
                if gs == wgs and (y + lstr - l) / lstr == wgs:
                    res.append(l) 
        sorted(res)
        return res
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """