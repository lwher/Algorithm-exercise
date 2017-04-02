class ListNode(object):
    def __init__(self, _val = 0, _prev = None, _next = None):
        self.val = _val
        self.prev = _prev
        self.next = _next
    
class LRUCache(object):
    
    def Delete(self, listnode):
        if listnode.prev == None:
            self.ListHead = listnode.next
        if listnode.next == None:
            self.ListTail = listnode.prev
        if listnode.prev != None:
            listnode.prev.next = listnode.next
        if listnode.next != None:
            listnode.next.prev = listnode.prev
        listnode.next = None
        listnode.prev = None
            
        
    def Insert(self, listnode):
        if self.ListHead == None:
            self.ListHead = listnode
            self.ListTail = listnode
            return
        self.ListTail.next = listnode
        listnode.prev = self.ListTail
        self.ListTail = listnode
        

    def __init__(self, capacity):
        self.dic = {}
        self.ListHead = None
        self.ListTail = None
        self.Total = 0
        self.capacity = capacity
        """
        :type capacity: int
        """
        

    def get(self, key):
        if key not in self.dic:
            return -1
        point = self.dic[key][1]
        if point == None:
            return -1
        self.Delete(point)
        self.Insert(point)
        self.dic[key] = (self.dic[key][0], point)
        return self.dic[key][0]
        """
        :rtype: int
        """
        

    def put(self, key, value):
        if key in self.dic:
            point = self.dic[key][1]
            if point != None:
                self.Delete(point)
                self.Insert(point)
                self.dic[key] = (value, point)
                return
        self.Total += 1
        if self.Total > self.capacity:
            self.dic[self.ListHead.val] = (0, None)
            self.Delete(self.ListHead)
            self.Total -= 1
        point = ListNode(_val = key)
        self.Insert(point)
        self.dic[key] = (value, point)
        
        """
        :type key: int
        :type value: int
        :rtype: nothing
        """
        