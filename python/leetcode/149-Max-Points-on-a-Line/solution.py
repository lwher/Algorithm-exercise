# Definition for a point.
# class Point(object):
#     def __init__(self, a=0, b=0):
#         self.x = a
#         self.y = b

class Solution(object):
    
    def abs(self, x):
        if x < 0:
            x = -x
        return x
    
    def gcd(self, a, b):
        if b == 0:
            return a
        return self.gcd(b, a % b)
    
    def maxPoints(self, points):
        Hash = {}
        length = len(points)
        if length <= 2:
            return length
        ans = 1
        for i in xrange(length):
            Hash.clear()
            Maxx = 0
            SamePoint = 1
            for j in xrange(length):
                if i == j:
                    continue
                dx = points[j].x - points[i].x
                dy = points[j].y - points[i].y
                
                if dx == 0 and dy == 0:
                    SamePoint += 1
                    continue
                if dx == 0:
                    dy = 1
                elif dy == 0:
                    dx = 1
                else:
                    d = self.gcd(self.abs(dx), self.abs(dy))
                    dx //= d
                    dy //= d
                    if dy < 0:
                        dx = -dx
                        dy = -dy
                if (dx, dy) in Hash:
                    Hash[(dx, dy)] += 1
                else:
                    Hash[(dx, dy)] = 1
                Maxx = max(Hash[(dx, dy)], Maxx)
            ans = max(ans, Maxx + SamePoint)
        return ans        
        """
        :type points: List[Point]
        :rtype: int
        """
        