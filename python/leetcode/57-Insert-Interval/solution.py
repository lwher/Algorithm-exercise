# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    def insert(self, intervals, newInterval):
        l = newInterval.start
        r = newInterval.end
        flag = False
        res = []
        for x in intervals:
            if (x.start >= l and x.start <= r) or (x.end >= l and x.end <= r) or (x.start >= l and x.end <= r) or (x.start <= l and x.end >= r):
                if l > x.start:
                    l = x.start
                if r < x.end:
                    r = x.end
            elif x.end < l:
                res.append(x)
            else:
                if flag == False:
                    res.append(Interval(l, r))
                    flag = True
                res.append(x)
        if flag == False:
            res.append(Interval(l, r))
        return res

        """
        :type intervals: List[Interval]
        :type newInterval: Interval
        :rtype: List[Interval]
        """
        