# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
       
        top = head
        cnt = 0
        while top:
            cnt+=1
            top = top.next
        
        if n == cnt:
            return head.next
        idx = cnt - n -1
       
        top = head
        while idx > 0:
            idx-=1
            top = top.next

        top.next = top.next.next
        
        return head