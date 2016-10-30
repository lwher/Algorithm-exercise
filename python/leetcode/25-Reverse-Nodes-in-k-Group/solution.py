# Definition for singly-linked list.
#class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):

    def reverseKpos(self, now, k):
        if k == 1:
            return now, now
        head, tail = self.reverseKpos(now.next, k - 1)
        tail.next = now
        return head, now

    def reverseKGroup(self, head, k):
        if head == None:
            return head
        if k == 1:
            return head
        next_head = head
        for x in range(k - 1):
            next_head = next_head.next
            if next_head == None:
                return head
        next_head = next_head.next
        new_head, new_tail = self.reverseKpos(head, k)
        new_tail.next = self.reverseKGroup(next_head, k)
        return new_head

        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
