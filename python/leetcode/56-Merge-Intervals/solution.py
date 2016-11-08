#Definition for an interval.
#class Interval(object):
#    def __init__(self, s=0, e=0):
#        self.start = s
#        self.end = e

class Solution(object):

    def merge(self, intervals):
        if len(intervals) == 0:
            return [] 
        intervals.sort(key = lambda x: (x.start, x.end))
        res = []
        l = -1e9 
        r = -1e9
        for x in intervals:
            if r < x.start:
                if r != -1e9:
                    res.append(Interval(l, r))
                l = x.start
                r = x.end
            else:
                if r < x.end:
                    r = x.end
        res.append(Interval(l, r))
        return res

        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
