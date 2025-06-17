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
        idx = cnt - n 
        if not idx:
            return head.next
        top = head
        
        while top:
            idx-=1
            if idx == 0:
                print(top)
                if top.next:
                    top.next = top.next.next
                else:
                    top.next = None
            if top:
                top = top.next
        return head