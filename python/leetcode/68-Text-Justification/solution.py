class Solution(object):
    def fullJustify(self, words, maxWidth):
        n = len(words)
        if n == 0 or maxWidth == 0:
            return [""]
        words.append('')
        res = []; l = 0; p = 1
        now = len(words[0])
        for r in range(1, n + 1):
            if r == n or now + len(words[r]) + p > maxWidth:
                nstr = ''
                if r != n:
                    if p > 1:
                        p -= 1
                    k = (maxWidth - now) % p
                    q = (maxWidth - now) // p
                    for x in range(l, r):
                        nstr += words[x]
                        y = q
                        if k > 0:
                            y += 1; k -= 1
                        if r - l == 1 or x != r - 1:
                            for z in range(y):
                                nstr += ' '
                else:
                    for x in range(l, r):
                        nstr += words[x]
                        if x != r - 1:
                            nstr += ' '
                    y = len(nstr)
                    for x in range(y, maxWidth):
                        nstr += ' '
                res.append(nstr)
                l = r; p = 1
                now = len(words[r])
            else:
                now += len(words[r])
                p += 1
        return res
        """
        :type words: List[str]
        :type maxWidth: int
        :rtype: List[str]
        """